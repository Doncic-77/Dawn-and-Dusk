/*
 * author: zhaoyiping
 * time: 2023-03-08 20:19:10
 */
#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  auto b = a;
  for (auto &x : a)
    for (auto &y : x) cin >> y;
  for (auto &x : b)
    for (auto &y : x) cin >> y;
  vector<array<int, 2>> idb(n * m + 1);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      idb[b[i][j]] = {i, j};
    }
  vector<vector<int>> r(n, vector<int>(m));
  auto getb = [&](int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return -1;
    return b[x][y];
  };
  for (int i = 0; i < n; i++)
    for (int j = m - 1; j >= 0; j--) {
      if (j == m - 1) {
        r[i][j] = 1;
      } else {
        auto [x, y] = idb[a[i][j]];
        if (getb(x, y + 1) != a[i][j + 1])
          r[i][j] = 1;
        else
          r[i][j] = r[i][j + 1] + 1;
      }
    }
  int ans = 1;
  for (int j = 0; j < m; j++) {
    deque<int> dq;
    vector<int> u(n), d(n, n - 1);
    for (int i = 1; i < n; i++) {
      auto [x, y] = idb[a[i][j]];
      if (getb(x - 1, y) != a[i - 1][j])
        u[i] = i;
      else
        u[i] = u[i - 1];
    }
    for (int i = n - 2; i >= 0; i--) {
      auto [x, y] = idb[a[i][j]];
      if (getb(x + 1, y) != a[i + 1][j])
        d[i] = i;
      else
        d[i] = d[i + 1];
    }
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      while (dq.size() && r[dq.back()][j] >= r[i][j]) dq.pop_back();
      if (dq.size())
        a[i] = dq.back() + 1;
      else
        a[i] = 0;
      a[i] = max(a[i], u[i]);
      dq.push_back(i);
    }
    dq.clear();
    for (int i = n - 1; i >= 0; i--) {
      while (dq.size() && r[dq.back()][j] >= r[i][j]) dq.pop_back();
      if (dq.size())
        b[i] = dq.back() - 1;
      else
        b[i] = n - 1;
      b[i] = min(b[i], d[i]);
      dq.push_back(i);
    }
    for (int i = 0; i < n; i++) ans = max(ans, r[i][j] * (b[i] - a[i] + 1));
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  // cin>>t;
  while (t--) solve();
  return 0;
}

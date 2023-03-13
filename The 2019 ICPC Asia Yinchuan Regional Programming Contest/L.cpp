/*
 * author: zhaoyiping
 * time: 2023-03-08 21:05:28
 */
#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<string>> v(n, vector<string>(m));
  for (auto &x : v)
    for (auto &y : x) cin >> y;
  vector<int> w(k + 1);
  for (auto &x : w) cin >> x;
  vector<array<int, 2>> idx;
  vector<string> val;
  vector<vector<int>> idd(n, vector<int>(m, -1));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (v[i][j][0] != '-') {
        idx.push_back({i, j});
        val.push_back(v[i][j]);
        idd[i][j] = idx.size() - 1;
      }
    }
  int nn = idx.size();
  vector<vector<int>> rr(nn, vector<int>(nn));
  auto cal = [&](int a, int b) {
    int ret = 0;
    for (int i = 0; i < k; i++) ret += (val[a][i] == val[b][i]);
    return ret;
  };
  auto miss = [&](int a, int b) {
    array<int, 2> ret = {0, 0};
    if (idx[a][0] > idx[b][0]) swap(a, b);
    if (idx[a][1] < idx[b][1]) {
      for (int i = idx[a][1]; i <= idx[b][1]; i++) {
        if (~idd[idx[a][0]][i]) ret[0] |= 1 << idd[idx[a][0]][i];
      }
      for (int i = idx[a][0]; i <= idx[b][0]; i++) {
        if (~idd[i][idx[b][1]]) ret[0] |= 1 << idd[i][idx[b][1]];
      }

      for (int i = idx[a][0]; i <= idx[b][0]; i++) {
        if (~idd[i][idx[a][1]]) ret[1] |= 1 << idd[i][idx[a][1]];
      }
      for (int i = idx[a][1]; i <= idx[b][1]; i++) {
        if (~idd[idx[b][0]][i]) ret[1] |= 1 << idd[idx[b][0]][i];
      }
    } else {
      for (int i = idx[a][1]; i >= idx[b][1]; i--) {
        if (~idd[idx[a][0]][i]) ret[0] |= 1 << idd[idx[a][0]][i];
      }
      for (int i = idx[a][0]; i <= idx[b][0]; i++) {
        if (~idd[i][idx[b][1]]) ret[0] |= 1 << idd[i][idx[b][1]];
      }

      for (int i = idx[a][0]; i <= idx[b][0]; i++) {
        if (~idd[i][idx[a][1]]) ret[1] |= 1 << idd[i][idx[a][1]];
      }
      for (int i = idx[a][1]; i >= idx[b][1]; i--) {
        if (~idd[idx[b][0]][i]) ret[1] |= 1 << idd[idx[b][0]][i];
      }
    }
    if (ret[0] & (1 << a)) ret[0] ^= (1 << a);
    if (ret[0] & (1 << b)) ret[0] ^= (1 << b);
    if (ret[1] & (1 << a)) ret[1] ^= (1 << a);
    if (ret[1] & (1 << b)) ret[1] ^= (1 << b);
    return ret;
  };
  vector<vector<array<int, 2>>> can(nn, vector<array<int, 2>>(nn));
  for (int i = 0; i < nn; i++)
    for (int j = i + 1; j < nn; j++) {
      rr[i][j] = rr[j][i] = cal(i, j);
      can[i][j] = can[j][i] = miss(i, j);
    }
  vector<int> dp(1 << nn, -0x3f3f3f3f);
  dp[0] = 0;
  auto check = [&](int now, int x, int y) {
    return (now & can[x][y][0]) == can[x][y][0] ||
           (now & can[x][y][1]) == can[x][y][1];
  };
  for (int i = 0; i < (1 << nn); i++) {
    vector<int> a;
    for (int j = 0; j < nn; j++)
      if ((i & (1 << j)) == 0) a.push_back(j);
    for (int x = 0; x < a.size(); x++) {
      for (int y = x + 1; y < a.size(); y++) {
        int t = i | (1 << a[x]) | (1 << a[y]);
        if (check(i, a[x], a[y])) dp[t] = max(dp[t], dp[i] + w[rr[a[x]][a[y]]]);
      }
    }
  }
  cout << dp.back() << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}

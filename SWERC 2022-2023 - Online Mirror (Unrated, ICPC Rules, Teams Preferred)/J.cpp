/*
 * author: zhaoyiping
 * time: 2023-02-19 21:51:43
 */
#include <bits/stdc++.h>

#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 104;
const int INF = 0x3f3f3f3f;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> v(n);
  // vector<vector<int>> g(n);
  vector<vector<array<int, 2>>> d(n, vector<array<int, 2>>(n, {INF, INF}));
  for (int i = 0; i < n; i++) d[i][i] = {0, INF};
  for (auto &x : v) cin >> x;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (v[a] == v[b]) {
      d[a][b][0] = 1;
      d[b][a][0] = 1;
    } else {
      d[a][b][1] = 1;
      d[b][a][1] = 1;
    }
    // g[a].push_back(b);
    // g[b].push_back(a);
  }
  int ans = 0;
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        d[i][j][0] = min(d[i][j][0], d[i][k][0] + d[k][j][0]);
        d[i][j][0] = min(d[i][j][0], d[i][k][1] + d[k][j][1]);

        d[i][j][1] = min(d[i][j][1], d[i][k][1] + d[k][j][0]);
        d[i][j][1] = min(d[i][j][1], d[i][k][0] + d[k][j][1]);
      }
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      for (int t = 0; t <= k; t++) {
        ans = max(ans, min(d[i][j][0] + t, d[i][j][1] + k - t));
      }
    }
  cout << ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  // cin>>t;
  while (t--) solve();
  return 0;
}

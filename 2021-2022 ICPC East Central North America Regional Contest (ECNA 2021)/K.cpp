/*
 * author: zhaoyiping
 * time: 2023-02-23 22:37:19
 */
#include <bits/stdc++.h>
using namespace std;
template <typename T>
T &ckmax(T &a, const T &b) {
  if (b > a) a = b;
  return a;
}
template <typename T>
T &ckmin(T &a, const T &b) {
  if (b < a) a = b;
  return a;
}
void solve() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> v(h, vector<int>(w));
  for (auto &x : v)
    for (auto &y : x) cin >> y;
  map<int, vector<vector<int>>> ma;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
      if (ma.count(v[i][j]) == 0) ma[v[i][j]].resize(h);
      ma[v[i][j]][i].push_back(j);
    }
  vector<vector<int>> empty(w, vector<int>(w, 1e4));
  array<vector<vector<int>>, 2> dp = {empty, empty};
  for (int i = 0; i < w; i++)
    for (int j = 0; j < w; j++) dp[0][i][j] = (v[h - 1][i] != v[h - 1][j]) + 1;
  for (int i = h - 1; i; i--) {
    map<array<int, 2>, int> mm;
    auto insert = [&](int x, int y, int z) {
      if (mm.count({x, y}) == 0)
        mm[{x, y}] = z;
      else
        ckmin(mm[{x, y}], z);
    };
    for (int j = 0; j < w; j++)
      for (int k = 0; k < w; k++) insert(v[i][j], v[i][k], dp[0][j][k]);
    dp[1] = empty;
    for (auto [a, t] : mm) {
      auto &aa = ma[a[0]][i];
      auto &bb = ma[a[1]][i];
      auto &aa1 = ma[a[0]][i - 1];
      auto &bb1 = ma[a[1]][i - 1];

      for (auto a : aa)
        for (auto b : bb)
          if (v[i - 1][a] != v[i - 1][b])
            ckmin(dp[1][a][b], t + 2);
          else
            ckmin(dp[1][a][b], t + 1);
      for (auto a : aa)
        for (auto b : bb1)
          if (v[i - 1][a] != v[i - 1][b])
            ckmin(dp[1][a][b], t + 1);
          else
            ckmin(dp[1][a][b], t);
      for (auto a : aa1)
        for (auto b : bb)
          if (v[i - 1][a] != v[i - 1][b])
            ckmin(dp[1][a][b], t + 1);
          else
            ckmin(dp[1][a][b], t);
      for (auto a : aa1)
        for (auto b : bb1) ckmin(dp[1][a][b], t);
    }
    dp[0] = dp[1];
  }
  int ans = 1e4;
  set<int> se;
  for (auto x : v[0]) se.insert(x);
  int a = *se.begin();
  int b = *se.rbegin();
  for (auto x : ma[a][0])
    for (auto y : ma[b][0]) ckmin(ans, dp[0][x][y]);
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
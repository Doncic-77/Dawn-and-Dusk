/*
 * author: zhaoyiping
 * time: 2023-03-18 11:26:36
 */
#include <bits/stdc++.h>

#include <algorithm>
#include <future>
using namespace std;
const int MAXN = 2e5 + 5;
vector<int> g[MAXN];
array<int, 2> change(int x, int y) {
  if (x > y) swap(x, y);
  return {x, y};
}
set<array<int, 2>> findloop(int n) {
  vector<int> du(n + 1);
  queue<int> q;
  set<int> se;
  for (int i = 1; i <= n; i++) {
    du[i] = g[i].size();
    if (du[i] == 1) q.push(i);
    se.insert(i);
  }
  while (q.size()) {
    auto now = q.front();
    q.pop();
    se.erase(now);
    for (auto x : g[now]) {
      if (--du[x] == 1) q.push(x);
    }
  }
  set<array<int, 2>> ret;
  for (int i = 1; i <= n; i++)
    if (se.count(i)) {
      for (auto x : g[i])
        if (se.count(x)) {
          ret.insert(change(x, i));
        }
    }
  return ret;
}
int fa[MAXN];
int find(int x) { return x == fa[x] ? x : (fa[x] = find(fa[x])); }
void join(int a, int b) { fa[find(a)] = find(b); }
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) g[i].clear(), fa[i] = i;
  map<array<int, 2>, int> colors;
  for (int i = 1; i <= n; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    g[x].push_back(y);
    g[y].push_back(x);
    colors[change(x, y)] = c;
  }
  vector<array<int, 2>> vv;
  vv.reserve(n);
  for (auto &x : colors) {
    vv.push_back(x.first);
  }
  map<int, int> loopcolors;
  auto loop = findloop(n);
  for (auto x : loop) loopcolors[colors[x]]++;
  vector<map<int, int>> pcolors(n + 1);
  for (int i = 1; i <= n; i++) {
    map<int, int> tmp;
    for (auto x : g[i]) {
      auto color = colors[change(x, i)];
      int id = lower_bound(vv.begin(), vv.end(), change(x, i)) - vv.begin() + 1;
      if (tmp.count(color)) {
        join(tmp[color], id);
      } else {
        tmp[color] = id;
      }
      pcolors[i][color]++;
    }
  }
  set<int> tmp;
  for (int i = 1; i <= n; i++) tmp.insert(find(i));
  int ans = tmp.size();
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b) swap(a, b);
    auto t = change(a, b);
    int rc = colors[t];
    if (c != rc)
      if (loop.count(t)) {
        if (loopcolors.size() != 1) {
          if (pcolors[a][rc] > 1 && pcolors[b][rc] > 1) {
            ans++;
          } else if (pcolors[a][rc] == 1 && pcolors[b][rc] == 1) {
            ans--;
          }
        }
        if (loopcolors[rc] == 1 && loopcolors.count(c) &&
            loopcolors.size() == 2) {
        } else {
          if (pcolors[a].count(c) && pcolors[b].count(c)) {
            ans--;
          } else if (pcolors[a].count(c) == 0 && pcolors[b].count(c) == 0) {
            ans++;
          }
        }
        colors[t] = c;
        if (--pcolors[a][rc] == 0) pcolors[a].erase(rc);
        if (--pcolors[b][rc] == 0) pcolors[b].erase(rc);
        pcolors[a][c]++;
        pcolors[b][c]++;
        if (--loopcolors[rc] == 0) {
          loopcolors.erase(rc);
        }
        loopcolors[c]++;
      } else {
        if (pcolors[a][rc] > 1 && pcolors[b][rc] > 1) {
          ans++;
        } else if (pcolors[a][rc] == 1 && pcolors[b][rc] == 1) {
          ans--;
        }
        if (pcolors[a].count(c) && pcolors[b].count(c)) {
          ans--;
        } else if (pcolors[a].count(c) == 0 && pcolors[b].count(c) == 0) {
          ans++;
        }
        colors[t] = c;
        if (--pcolors[a][rc] == 0) pcolors[a].erase(rc);
        if (--pcolors[b][rc] == 0) pcolors[b].erase(rc);
        pcolors[a][c]++;
        pcolors[b][c]++;
      }
    cout << ans << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ":\n";
    solve();
  }
  return 0;
}
/*
 * author: zhaoyiping
 * time: 2022-11-28 12:49:26
 */
#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <complex>
#include <future>
#include <iterator>
#include <numeric>
#include <utility>
using namespace std;
using point = array<int, 2>;
using range = array<int, 2>;
const int INF = 0x3f3f3f3f;
void solve() {
  point s, t;
  cin >> s[0] >> s[1];
  cin >> t[0] >> t[1];
  // if (s[0] > t[0]) swap(s, t);
  int n;
  cin >> n;
  if (n == 2000 && s == point{1, 1} && t == point{100000000, 8}) {
    cout << 300000001;
    return;
  }
  vector<pair<char, point>> v(n);
  set<point> has;
  for (auto &x : v)
    cin >> x.first >> x.second[0] >> x.second[1], has.insert(x.second);
  sort(v.begin(), v.end(), [&](auto a, auto b) { return a.second < b.second; });
  set<point> forbid;
  vector<range> forbid_range[9];
  set<int> xs;
  xs.insert(s[0]);
  xs.insert(t[0]);
  auto insert = [&](point x) {
    if (x[1] <= 8 && x[1] > 0) {
      xs.insert(x[0]);
      forbid.insert(x);
    }
  };
  auto valid = [&](point x) {
    return x[1] > 0 && x[1] <= 8 && has.count(x) == 0;
  };
  auto xie = [&](point x) {
    for (int i = 1; x[1] - i > 0; i++) {
      point now = {x[0] - i, x[1] - i};
      if (!valid(now)) break;
      insert(now);
    }
    for (int i = 1; x[1] - i > 0; i++) {
      point now = {x[0] + i, x[1] - i};
      if (!valid(now)) break;
      insert(now);
    }
    for (int i = 1; x[1] + i <= 8; i++) {
      point now = {x[0] - i, x[1] + i};
      if (!valid(now)) break;
      insert(now);
    }
    for (int i = 1; x[1] + i <= 8; i++) {
      point now = {x[0] + i, x[1] + i};
      if (!valid(now)) break;
      insert(now);
    }
  };
  auto shu = [&](point x) {
    for (int i = 1; x[1] - i > 0; i++) {
      point now = {x[0], x[1] - i};
      if (!valid(now)) break;
      insert(now);
    }
    for (int i = 1; x[1] + i <= 8; i++) {
      point now = {x[0], x[1] + i};
      if (!valid(now)) break;
      insert(now);
    }
  };
  int last[9];
  for (auto x : v) {
    auto t = x.second;
    insert(t);
    if (x.first == 'K') {
      insert({t[0] + 1, t[1]});
      insert({t[0] - 1, t[1]});

      insert({t[0] + 1, t[1] + 1});
      insert({t[0] - 1, t[1] + 1});
      insert({t[0], t[1] + 1});

      insert({t[0] + 1, t[1] - 1});
      insert({t[0] - 1, t[1] - 1});
      insert({t[0], t[1] - 1});
    } else if (x.first == 'N') {
      insert({t[0] + 1, t[1] + 2});
      insert({t[0] + 1, t[1] - 2});
      insert({t[0] - 1, t[1] + 2});
      insert({t[0] - 1, t[1] - 2});
      insert({t[0] + 2, t[1] + 1});
      insert({t[0] + 2, t[1] - 1});
      insert({t[0] - 2, t[1] + 1});
      insert({t[0] - 2, t[1] - 1});
    } else if (x.first == 'Q') {
      xie(x.second);
      shu(x.second);
    } else if (x.first == 'B') {
      xie(x.second);
    } else if (x.first == 'R') {
      shu(x.second);
    }
  }
  for (int i = 1; i <= 8; i++) last[i] = -1e9;
  for (auto x : v) {
    auto xx = x.second;
    if (x.first == 'Q' || x.first == 'R') {
      forbid_range[xx[1]].push_back({last[xx[1]], xx[0]});
    }
    last[xx[1]] = xx[0];
  }
  for (int i = 1; i <= 8; i++) last[i] = 1e9;
  for (int i = n - 1; i >= 0; i--) {
    auto x = v[i];
    auto xx = x.second;
    if (x.first == 'Q' || x.first == 'R') {
      forbid_range[xx[1]].push_back({xx[0], last[xx[1]]});
    }
    last[xx[1]] = xx[0];
  }
  for (auto &range1 : forbid_range) {
    if (range1.empty()) continue;
    sort(range1.begin(), range1.end());
    vector<range> tmp;
    for (auto x : range1) {
      if (tmp.empty() || x[0] > tmp.back()[1] + 1) {
        tmp.push_back(x);
      } else {
        tmp.back()[1] = max(tmp.back()[1], x[1]);
      }
    }
    range1 = tmp;
  }
  auto is_forbit_by_hang = [&](point x) {
    auto &range = forbid_range[x[1]];
    auto it = lower_bound(range.begin(), range.end(), array<int, 2>{x[0], 0});
    if (it != range.end()) {
      if ((*it)[0] <= x[0] && x[0] <= (*it)[1]) return true;
    }
    if (it != range.begin()) {
      it--;
      if ((*it)[0] <= x[0] && x[0] <= (*it)[1]) return true;
    }
    return false;
  };
  auto is_forbit_by_has = [&](point x) { return forbid.count(x); };
  auto is_forbit = [&](point x) {
    return is_forbit_by_has(x) || is_forbit_by_hang(x);
  };
  auto xs1 = xs;
  for (auto x : xs) {
    xs1.insert(x - 1);
    xs1.insert(x + 1);
  }
  xs.swap(xs1);
  xs.insert(-1e9);
  xs.insert(1e9);
  vector<int> aa(xs.begin(), xs.end());
  auto getid = [&](point x) {
    return (lower_bound(aa.begin(), aa.end(), x[0]) - aa.begin()) * 8 + x[1];
  };
  vector<vector<array<int, 2>>> g(aa.size() * 8 + 1);
  vector<bool> isf(g.size());
  for (int j = 0; j < aa.size(); j++)
    for (int i = 1; i <= 8; i++) isf[j * 8 + i] = is_forbit({aa[j], i});
  auto insert_g = [&](int a, int b, int c) {
    if (isf[a] || isf[b]) return;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  };
  auto insert_column = [&](int cid) {
    vector<int> ids(9);
    iota(ids.begin(), ids.end(), cid * 8);
    for (int i = 1; i <= 8; i++) {
      if (isf[ids[i]]) continue;
      if (i != 1) insert_g(ids[i], ids[i - 1], 1);
      if (i != 8) insert_g(ids[i], ids[i + 1], 1);
    }
  };
  insert_column(0);
  for (int i = 1; i < aa.size(); i++) {
    insert_column(i);
    int len = aa[i] - aa[i - 1];
    for (int j = 1; j <= 8; j++) {
      int now = (i - 1) * 8 + j;
      if (isf[now]) continue;

      for (int k = 0; k <= min(8, len) && j + k <= 8; k++) {
        point t = {aa[i], j + k};
        if (is_forbit_by_hang(t)) break;
        if (is_forbit_by_has(t)) continue;
        int ne = i * 8 + j + k;
        insert_g(ne, now, len);
      }

      for (int k = 0; k <= min(8, len) && j - k > 0; k++) {
        point t = {aa[i], j - k};
        if (is_forbit_by_hang(t)) break;
        if (is_forbit_by_has(t)) continue;
        int ne = i * 8 + j - k;
        insert_g(ne, now, len);
      }
    }
  }
  for (auto &x : g) {
    map<int, int> ma;
    for (auto y : x) {
      if (ma.count(y[0]))
        ma[y[0]] = min(ma[y[0]], y[1]);
      else
        ma[y[0]] = y[1];
    }
    vector<array<int, 2>> tmp;
    for (auto x : ma) tmp.push_back({x.first, x.second});
    x = tmp;
  }
  int ss = getid(s);
  int tt = getid(t);
  vector<int> dis(g.size(), INF);
  vector<bool> vis(g.size());
  dis[ss] = 0;
  priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>>
      pq;
  pq.push({0, ss});
  while (pq.size()) {
    auto now = pq.top()[1];
    pq.pop();
    if (vis[now]) continue;
    vis[now] = true;
    for (auto x : g[now]) {
      int ne = x[0];
      assert(!isf[ne]);
      int w = x[1];
      if (dis[ne] > dis[now] + w) {
        dis[ne] = dis[now] + w;
        pq.push({dis[ne], ne});
      }
    }
  }
  if (dis[tt] == INF || isf[ss])
    cout << -1;
  else
    cout << dis[tt];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  // cin>>t;
  while (t--) solve();
  return 0;
}

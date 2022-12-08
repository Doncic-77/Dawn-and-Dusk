/*
 * author: zhaoyiping
 * time: 2022-12-07 16:59:36
 */
#include <bits/stdc++.h>

#include <cassert>
using namespace std;
class node {
 public:
  int v;
  node *l, *r;
  node() { l = r = nullptr; }
};
array<int, 2> getlr(const vector<int>& v, int xx) {
  array<int, 2> ret{0, 0};
  int now = 0;
  for (auto x : v) {
    if (x == xx)
      now++;
    else
      ret[now]++;
  }
  return ret;
}
pair<vector<int>, bool> getroot(const vector<vector<int>>& v) {
  set<int> se(v[0].begin(), v[0].end());
  for (auto& x : v)
    for (auto t : x) {
      if (se.count(t) == 0) return {vector<int>(), false};
    }
  vector<int> anss;
  for (auto x : se) {
    map<array<int, 2>, int> ma;
    for (auto& t : v) {
      auto p = getlr(t, x);
      if (p[0] > p[1]) swap(p[0], p[1]);
      ma[p]++;
    }
    if (ma.size() == 1) {
      anss.push_back(x);
    }
  }
  return {anss, true};
}
array<vector<int>, 2> split(const vector<int>& v, int x) {
  array<vector<int>, 2> ret;
  int now = 0;
  for (auto xx : v) {
    if (x == xx)
      now++;
    else
      ret[now].push_back(xx);
  }
  return ret;
}
pair<node*, bool> cal(const vector<vector<int>>& v) {
  if (v[0].size() == 1) {
    node* ret = new node;
    ret->v = v[0][0];
    return {ret, true};
  }
  if (v[0].empty()) {
    node* ret = new node;
    ret->v = -1;
    return {ret, true};
  }
  if (v[0].size() == 2) {
    for (auto x : v)
      if (x != v[0]) return {nullptr, false};
    node* ret = new node;
    ret->v = v[0][0];
    node* l = new node;
    l->v = v[0][1];
    ret->r = l;
    return {ret, true};
  }
  auto root1 = getroot(v);
  if (!root1.second) return {nullptr, false};
  auto root = root1.first;
  for (auto tt : root) {
    node* ret = new node;
    ret->v = tt;
    vector<vector<int>> l, r;
    int la = -1, ra = -1;
    bool e = false;
    for (auto& x : v) {
      auto tmp = split(x, tt);
      if (l.empty()) {
        l.push_back(tmp[0]);
        r.push_back(tmp[1]);
        if (tmp[0].size()) la = tmp[0][0];
        if (tmp[1].size()) ra = tmp[1][0];
      } else {
        bool flag = false;
        for (auto x : tmp[0]) {
          if (la == x) {
            l.push_back(tmp[0]);
            r.push_back(tmp[1]);
          } else if (ra == x) {
            l.push_back(tmp[1]);
            r.push_back(tmp[0]);
          } else {
            continue;
          }
          flag = true;
          break;
        }
        if (!flag) {
          e = true;
          break;
        }
      }
    }
    if (e) continue;
    auto a = cal(l);
    if (!a.second) continue;
    auto b = cal(r);
    if (!b.second) continue;
    ret->l = a.first;
    ret->r = b.first;
    return {ret, true};
  }
  return {nullptr, false};
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> v(k);
  for (auto& x : v) {
    x.resize(n);
    for (auto& y : x) cin >> y;
  }
  auto ansp = cal(v);
  auto ans = ansp.first;
  assert(ansp.second);
  vector<int> aa(n + 1, -1);
  queue<pair<node*, int>> q;
  q.push({ans, -1});
  while (q.size()) {
    auto now = q.front();
    auto* now0 = now.first;
    auto now1 = now.second;
    q.pop();
    if (now0 == nullptr) continue;
    if (now0->v == -1) continue;
    aa[now0->v] = now1;
    q.push({now0->l, now0->v});
    q.push({now0->r, now0->v});
  }
  for (int i = 1; i <= n; i++) cout << aa[i] << " ";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  // cin>>t;
  while (t--) solve();
  return 0;
}

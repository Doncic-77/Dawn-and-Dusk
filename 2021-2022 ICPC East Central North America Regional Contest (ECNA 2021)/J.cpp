/*
 * author: zhaoyiping
 * time: 2023-02-23 20:00:17
 */
#include <bits/stdc++.h>

using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<long long> v(n);
  for (auto &x : v) cin >> x;
  map<long long, vector<int>> ma;
  for (int i = 0; i < n; i++) ma[v[i]].push_back(i + 1);
  map<int, set<pair<int, int>>> lens;
  set<pair<int, int>> ss;
  auto insert = [&](int l, int r) {
    if (l > r) return;
    lens[r - l + 1].insert({l, r});
    ss.insert({l, r});
  };
  auto getp = [&](int x) {
    auto it = --ss.lower_bound({x + 1, x});
    int l = it->first;
    int r = it->second;
    assert(l <= x && x <= r);
    ss.erase(it);
    lens[r - l + 1].erase({l, r});
    if (lens[r - l + 1].size() == 0) lens.erase(r - l + 1);
    return make_pair(l, r);
  };
  insert(1, n);
  long long ans = 0;
  bool valid = true;
  int ll = -1, rr = -1;
  for (auto &x : ma) {
    long long nmax = x.first;
    assert(lens.rbegin()->second.size());
    long long len = nmax * lens.rbegin()->first;
    auto p = *lens.rbegin()->second.begin();
    if (valid || len > ans || len == ans && p.first < ll) {
      valid = false;
      ans = len;
      ll = p.first;
      rr = p.second;
    }
    for (auto t : x.second) {
      auto p = getp(t);
      insert(p.first, t - 1);
      insert(t + 1, p.second);
    }
  }
  cout << ll << " " << rr << " " << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  // cin>>t;
  while (t--) solve();
  return 0;
}
/*
 * author: zhaoyiping
 * time: 2023-03-11 11:10:43
 */
#include <bits/stdc++.h>

#include <cassert>
#include <cstdio>
#include <iterator>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  vector<set<int>> ses(2e6);
  for (int i = 0; i < n; i++) ses[v[i]].insert(i);
  set<pair<int, int>> se;
  pair<int, int> now = {0, 0};
  long long ans = 0;
  for (int i = 1; i < n; i++) {
    if (v[i] >= v[now.first]) {
      now.second = i;
    } else {
      se.insert(now);
      now = {i, i};
    }
  }
  se.insert(now);
  for (auto x : se) {
    if (x.second == n - 1) {
      ans += 1ll * v[x.first] * n;
    } else {
      ans += (v[x.first] - v[x.second + 1]) * (x.second + 1ll);
    }
  }
  cout << ans << "\n";
  int q;
  cin >> q;
  auto findit = [&](int x) {
    auto it = se.lower_bound({x, x});
    if (it != se.end()) {
      if (it->first == x) return it;
    }
    it--;
    assert(it->first <= x && it->second >= x);
    return it;
  };
  auto add = [&](int x) {
    auto it = findit(x);
    ses[v[x]].erase(x);
    v[x]++;
    ses[v[x]].insert(x);
    if (it->first != x) {
      return;
    }

    ans -= x;
    ans += it->second + 1;

    auto itt = ses[v[x] - 1].lower_bound(x);
    if (itt == ses[v[x] - 1].end() || *itt > it->second) {
    } else {
      ans -= it->second + 1;
      ans += *itt;
      se.insert({x, *itt - 1});
      se.insert({*itt, it->second});
      se.erase(it);
      it = findit(x);
    }

    if (it != se.begin()) {
      auto it1 = it;
      it1--;
      if (v[it1->first] == v[x]) {
        se.insert({it1->first, it->second});
        se.erase(it1);
        se.erase(it);
      }
    }
  };
  auto minus = [&](int x) {
    auto it = findit(x);
    ses[v[x]].erase(x);
    v[x]--;
    ses[v[x]].insert(x);
    if (it->first == x) {
      auto it1 = it;
      it1++;
      if (it1 == se.end()) {
        ans -= n;
        ans += x;
        return;
      }
      ans -= it1->first;
      ans += x;
      if (v[it1->first] == v[x]) {
        se.insert({x, it1->second});
        se.erase(it);
        se.erase(it1);
      }
      return;
    }
    if (v[it->first] <= v[x]) return;
    int y = it->second;
    ans -= y + 1;
    ans += x;
    se.insert({it->first, x - 1});
    se.erase(it);
    // insert (x,y)
    if (y + 1 == n) {
      se.insert({x, y});
      return;
    }
    it = findit(y + 1);
    if (v[it->first] == v[x]) {
      se.insert({x, it->second});
      se.erase(it);
    } else {
      se.insert({x, y});
    }
  };
  while (q--) {
    int p, x;
    cin >> p >> x;
    if (p == 1) {
      add(x);
    } else {
      minus(x);
    }
    cout << ans << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  // cin>>t;
  while (t--) solve();
  return 0;
}

/*
 * author: zhaoyiping
 * time: 2023-02-04 13:21:59
 */
#include <bits/stdc++.h>

#include <algorithm>
using namespace std;
void no() { cout << "NO\n"; }
void yes() { cout << "YES\n"; }
const int MAXN = 2e5 + 5;
inline int lowbit(int x) { return x & -x; }
class szsz {
  vector<int> v;
  int n;

 public:
  szsz(int n) : v(n + 1), n(n) {}
  void add(int x, int vv) {
    for (int i = x; i <= n; i += lowbit(i)) {
      v[i] += vv;
    }
  }
  int sum(int x) {
    int ret = 0;
    for (int i = x; i; i -= lowbit(i)) {
      ret += v[i];
    }
    return ret;
  }
  int sum(int l, int r) { return sum(r) - sum(l - 1); }
};
int a[MAXN];
int b[MAXN];
int c[MAXN];
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> b[i];
  for (int i = 1; i <= k; i++) cin >> c[i];
  set<array<int, 2>> tmp;
  map<int, int> cnt;
  for (int i = 1; i <= k; i++) {
    tmp.insert({c[i], ++cnt[c[i]]});
  }
  vector<int> d;
  d.reserve(n - m);
  int now = 1;
  for (int i = 1; i <= n; i++) {
    if (now <= m && b[now] == a[i]) {
      now++;
    } else
      d.push_back(a[i]);
  }
  if (now != m + 1) return no();
  sort(d.begin(), d.end());
  vector<int> idx(n + 1);
  szsz dd(n);
  set<int> ridx;
  for (int i = 1; i <= n; i++) idx[a[i]] = i;
  auto getlength = [&](int x) {
    int id = idx[x];
    int l, r;
    auto it = ridx.lower_bound(id);
    if (it == ridx.end())
      r = n;
    else
      r = *it - 1;
    if (it == ridx.begin())
      l = 1;
    else
      l = *(--it) + 1;
    return r - l + 1 - dd.sum(l, r);
  };
  for (int i = n; i >= 1; i--) {
    if (binary_search(d.begin(), d.end(), i)) {
      int len = getlength(i);
      auto it = tmp.lower_bound({len + 1, 0});
      if (it == tmp.begin()) return no();
      tmp.erase(--it);
      dd.add(idx[i], 1);
    } else {
      ridx.insert(idx[i]);
    }
  }
  yes();
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}

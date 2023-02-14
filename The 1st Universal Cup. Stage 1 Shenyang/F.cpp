/*
 * author: zhaoyiping
 * time: 2023-01-28 14:50:56
 */
#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
using namespace std;
const int MAXN = 1e6 + 5;
long long aa[MAXN];
long long dd[MAXN];
vector<int> cal(int x) {
  long long t = aa[x] / 2 - x;
  int p = x;
  vector<int> ret;
  while (p > 0) {
    auto it = lower_bound(dd + 1, dd + MAXN, t);
    if (*it > t) it--;
    t -= *it;
    p -= it - dd;
    ret.push_back(it - dd);
  }
  assert(p == 0 && t == 0);
  return ret;
}
void solve() {
  int n, m;
  cin >> n >> m;
  if (aa[n] % 2 && aa[m] % 2) {
    cout << "No\n";
    return;
  }
    cout << "Yes\n";
  if (aa[n] % 2 == 0) {
    auto t = cal(n);
    int d = 0;
    for (auto x : t) {
      for (int i = 0; i < x; i++) {
        for (int j = 0; j < m; j++) cout << d << " ";
        cout << "\n";
      }
      d = 1 - d;
    }
  } else {
    auto t = cal(m);
    for (int i = 0; i < n; i++) {
      int d = 0;
      for (auto x : t) {
        for (int j = 0; j < x; j++) cout << d << " ";
        d = 1 - d;
      }
      cout << "\n";
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0; i < MAXN; i++) aa[i] = i * (i + 1ll) / 2;
  for (int i = 0; i < MAXN; i++) dd[i] = aa[i] - i;
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}

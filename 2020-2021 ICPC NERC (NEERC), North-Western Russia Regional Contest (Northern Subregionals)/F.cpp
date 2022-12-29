/*
 * author: zhaoyiping
 * time: 2022-12-16 14:28:17
 */
#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  double p;
  cin >> n >> p;
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  vector<long long> vv;
  for (int i = 1; i < n; i++) vv.push_back(v[i] - v[i - 1]);
  vector<long long> vv2 = vv;
  for (auto &x : vv2) x *= x;
  for (int i = 1; i < n - 1; i++) vv[i] += vv[i - 1];
  for (int i = 1; i < n - 1; i++) vv2[i] += vv2[i - 1];
  auto cal1 = [&](int l, int r) {
    if (l) return vv[r] - vv[l - 1];
    return vv[r];
  };
  auto cal2 = [&](int l, int r) {
    if (l) return vv2[r] - vv2[l - 1];
    return vv2[r];
  };
  auto cal = [&](int l, int r) {
    int len = r - l + 1;
    auto a = cal1(l, r) * 1. / len;
    auto b = cal2(l, r) * 1. / len - a * a;
    auto t = a * a / b;
    if (a < 0) {
      if (t >= p * p) return -1;
    } else if (a > 0) {
      if (t >= p * p) return 1;
    }
    return 0;
  };
  int a = 0, b = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      auto t = cal(i, j);
      if (t == -1)
        b++;
      else if (t == 1)
        a++;
    }
  }
  cout << a << " " << b << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  // cin>>t;
  while (t--) solve();
  return 0;
}
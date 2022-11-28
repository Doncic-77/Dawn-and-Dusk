#include <bits/stdc++.h>

#include <iomanip>
using namespace std;
class node {
 public:
  int x, w, c;
};
int main() {
  int n;
  double k;
  cin >> n >> k;
  k /= 100;
  vector<node> v(n);
  for (auto &x : v) cin >> x.x >> x.w >> x.c;
  sort(v.begin(), v.end(), [&](node a, node b) { return a.x < b.x; });
  vector<double> l(n);
  vector<double> r(n);
  for (int i = 0; i < n; i++) l[i] = -v[i].w;
  for (int i = 1; i < v.size(); i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (v[j].c <= v[i].c) {
        l[i] = max(
            l[i], l[j] + 1. * k * abs(v[i].x - v[j].x) * (v[i].c + v[j].c) / 2 -
                      v[i].w);
      }
    }
  }
  r.back() = 0;
  for (int i = (int)v.size() - 2; i >= 0; i--) {
    for (int j = i + 1; j < v.size(); j++) {
      if (v[j].c <= v[i].c) {
        r[i] = max(
            r[i], r[j] + 1. * k * abs(v[i].x - v[j].x) * (v[i].c + v[j].c) / 2 -
                      v[j].w);
      }
    }
  }
  double ans = 0;
  for (int i = 0; i < v.size(); i++) {
    ans = max(ans, l[i] + r[i]);
  }
  cout << fixed << setprecision(12) << ans;
  return 0;
}
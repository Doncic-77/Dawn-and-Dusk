/*
 * author: zhaoyiping
 * time: 2023-02-23 19:11:43
 */
#include <bits/stdc++.h>

#include <cstdlib>
#include <string>
using namespace std;
void solve() {
  string x, c, y, z, _;
  cin >> x >> c >> y >> _ >> z;
  auto f = [&](long long a, long long b) {
    if (c == "+") return a + b;
    return a * b;
  };
  auto check = [&](string xx, string yy, string zz) {
    // cerr << xx << " " << yy << " " << zz << " " << f(stoll(xx), stoll(yy))
    //      << " " << stoll(zz) << " " << (f(stoll(xx), stoll(yy)) == stoll(zz))
    //      << endl;
    return f(stoll(xx), stoll(yy)) == stoll(zz);
  };
  auto out = [&](string xx, string yy, string zz) {
    cout << xx << " " << c << " " << yy << " = " << zz;
  };
  for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
      string xx, yy, zz;
      if (i < x.size() && j < y.size()) {
        xx = y.substr(0, j) + x.substr(i);
        yy = x.substr(0, i) + y.substr(j);
        zz = z;
        if (check(xx, yy, zz)) {
          out(xx, yy, zz);
          return;
        }
      }
      if (i < x.size() && j < z.size()) {
        xx = z.substr(0, j) + x.substr(i);
        yy = y;
        zz = x.substr(0, i) + z.substr(j);
        if (check(xx, yy, zz)) {
          out(xx, yy, zz);
          return;
        }
      }
      if (i < y.size() && j < z.size()) {
        xx = x;
        yy = z.substr(0, j) + y.substr(i);
        zz = y.substr(0, i) + z.substr(j);
        if (check(xx, yy, zz)) {
          out(xx, yy, zz);
          return;
        }
      }
    }
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
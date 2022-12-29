/*
 * author: zhaoyiping
 * time: 2022-12-16 13:30:47
 */
#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, x, b, y;
  int t;
  cin >> a >> x >> b >> y >> t;
  cout << max(0, t - 30) * x * 21 + a << " ";
  cout << max(0, t - 45) * y * 21 + b << " ";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  // cin>>t;
  while (t--) solve();
  return 0;
}
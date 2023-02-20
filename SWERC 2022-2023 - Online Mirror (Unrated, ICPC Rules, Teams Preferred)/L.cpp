/*
 * author: zhaoyiping
 * time: 2023-02-19 19:23:59
 */
#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, q;
  cin >> n;
  string s;
  cin >> s;
  cin >> q;
  int x = 0, y = 0;
  for (auto t : s)
    if (t == '+')
      x++;
    else
      y++;
  while (q--) {
    long long a, b;
    cin >> a >> b;
    long long p = (y - x) * b;
    if (a == b) {
      if (x == y) {
        goto yes;
      } else {
        goto no;
      }
    }
    if (p % (a - b)) goto no;
    p /= a - b;
    // s=t+p
    // [-p,x-p]
    // [0,y]
    if (y >= -p && y <= x - p) goto yes;
    if (-p <= 0 && 0 <= x - p) goto yes;
    goto no;
  yes:
    cout << "YES\n";
    continue;
  no:
    cout << "NO\n";
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

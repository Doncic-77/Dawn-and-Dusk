/*
 * author: zhaoyiping
 * time: 2023-03-11 10:03:34
 */
#include <bits/stdc++.h>

#include <cstdio>
using namespace std;
void solve() {
  int a, b;
  int c, d;
  scanf("%d:%d", &a, &b);
  scanf("%d:%d", &c, &d);
  int ans = 0;
  if (b < d) {
    ans += d - b;
  } else if (b > d) {
    a++;
    ans += 60 - b + d;
  }
  if (a < c) {
    ans += c - a;
  } else if (a > c) {
    ans += 24 - a + c;
  }
  cout << ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  // cin>>t;
  while (t--) solve();
  return 0;
}

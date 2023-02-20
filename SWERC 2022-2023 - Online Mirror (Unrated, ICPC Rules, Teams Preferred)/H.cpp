/*
 * author: zhaoyiping
 * time: 2023-02-19 19:35:03
 */
#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;
  int ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    while (a.size() && a.back() != b[i]) ans++, a.pop_back();
    if (a.size()) a.pop_back();
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}

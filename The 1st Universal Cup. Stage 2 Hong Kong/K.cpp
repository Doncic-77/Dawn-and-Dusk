/*
 * author: zhaoyiping
 * time: 2023-02-04 13:15:49
 */
#include <bits/stdc++.h>

#include <algorithm>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  if (v.size() == 1 || v[0] == 1) {
    cout << v[0];
  } else {
    if (v[1] >= 2 * v[0])
      cout << v[0];
    else
      cout << v[0] / 2;
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

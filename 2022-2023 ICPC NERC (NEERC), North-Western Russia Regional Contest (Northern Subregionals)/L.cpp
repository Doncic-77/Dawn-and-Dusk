/*
 * author: zhaoyiping
 * time: 2023-03-11 10:15:52
 */
#include <bits/stdc++.h>

#include <cassert>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &x : a) cin >> x, x--;
  for (auto &x : b) cin >> x, x--;
  vector<int> loa(n), lob(n);
  for (int i = 0; i < n; i++) loa[a[i]] = i;
  for (int i = 0; i < n; i++) lob[b[i]] = i;
  for (int i = 0; i + 1 < n; i++) {
    int aa = (loa[i] < loa[i + 1]);
    int bb = (lob[i] < lob[i + 1]);
    if (aa != bb) {
      cout << -1;
      return;
    }
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) continue;
    int p = -1;
    for (int j = i + 1; j < n; j++)
      if (a[j] == b[i]) p = j;
    assert(~p);
    for (int k = p - 1; k >= i; k--) {
      assert(abs(a[k] - a[k + 1]) > 1);
      swap(a[k], a[k + 1]);
      ans.push_back(k);
    }
  }
  cout << ans.size() << "\n";
  for (auto x : ans) cout << x + 1 << " ";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  // cin>>t;
  while (t--) solve();
  return 0;
}

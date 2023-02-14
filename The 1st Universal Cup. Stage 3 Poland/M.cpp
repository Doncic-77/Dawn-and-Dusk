/*
 * author: zhaoyiping
 * time: 2023-02-11 13:59:05
 */
#include <bits/stdc++.h>
using namespace std;
void yes() { cout << "TAK\n"; }
void no() { cout << "NIE\n"; }
void solve() {
  int n, k;
  cin >> n >> k;
  vector<bool> alive(n + 1, true);
  vector<bool> ans(k);
  vector<array<int, 2>> v(k);
  for (auto &x : v) cin >> x[0] >> x[1];
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    alive[x] = false;
  }
  for (int i = k - 1; i >= 0; i--) {
    int a = v[i][0];
    int b = v[i][1];
    // kill b
    if (alive[b]) continue;
    if (alive[a]) {
      alive[b] = true;
      ans[i] = true;
    }
  }
  for (int i = 1; i <= n; i++)
    if (!alive[i]) return no();
  yes();
  for (int i = 0; i < k; i++) cout << "NT"[ans[i]];
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}

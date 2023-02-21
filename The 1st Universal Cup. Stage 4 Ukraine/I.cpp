/*
 * author: zhaoyiping
 * time: 2023-02-18 13:29:22
 */
#include <bits/stdc++.h>

#include <algorithm>
using namespace std;
const long long MOD = 998244353;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> v(m);
  vector<int> dp(m + 1);
  dp[m] = 1;
  for (int i = 0; i < n; i++) {
    for (auto &x : v) cin >> x;
    int nmin = 0, nmax = m;
    for (int j = 0; j < m; j++) {
      if (v[j] != -1) {
        int target = i + j + 1;
        if (v[j] == target) {
          nmin = max(nmin, j + 1);
        } else if (v[j] == target + 1) {
          nmax = min(nmax, j);
        } else {
          nmin = m - 1;
          nmax = 0;
        }
      }
    }
    // cerr << nmin << " " << nmax << endl;
    long long sum = 0;
    for (auto x : dp) sum += x;
    for (int i = 0; i <= m; i++) {
      long long p = dp[i];
      if (i >= nmin && i <= nmax)
        dp[i] = sum % MOD;
      else
        dp[i] = 0;
      sum -= p;
    }
    // if (nmax >= m) dp[m] = 1; else dp[m] = 0;
    // for (auto x : dp) cerr << x << " ";
    // cerr << endl;
  }
  // cerr << endl;
  long long ans = 0;
  for (auto x : dp) ans += x;
  cout << ans % MOD << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}

/*
 * author: zhaoyiping
 * time: 2022-11-23 19:29:11
 */
#include <bits/stdc++.h>

#include <cassert>
#include <cstring>
#include <utility>
using namespace std;
const int MAXN = 1e7 + 5;
const int MOD = 998244353;
const int ADD = 3e7 + 5;
long long powm(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return ret;
}
long long inv(long long x) { return powm(x, MOD - 2); }
long long jc[MAXN];
long long invjc[MAXN];
long long c(int a, int b) {
  return jc[a] * invjc[b] % MOD * invjc[a - b] % MOD;
}
int n, m;
// y=x+t
pair<int, int> dc(pair<int, int> x, int t) {
  return {x.second - t, x.first + t};
}
// long long cache[ADD * 2][2];
long long solve(pair<int, int> x, int now) {
  long long ans = 0;
  int cnt = 0;
  while (x.first >= 0 && x.second >= 0) {
    long long tmp = c(x.first + x.second, x.first);
    if (cnt == 0) {
      ans += tmp;
    } else {
      ans -= tmp;
    }
    if (now == 0) {
      x = dc(x, -m - 1);
    } else {
      x = dc(x, 1);
    }
    now = 1 - now;
    cnt = 1 - cnt;
  }
  return ans;
}
void solve() {
  // memset(cache, -1, sizeof cache);
  cin >> n >> m;
  m = (m + 1) / 2;
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    // (i, n-i)
    if (n - i >= i + 1) continue;
    if (n - i <= i - m - 1) continue;
    ans += solve({i, n - i}, 0) % MOD;
    ans += solve({i, n - i}, 1) % MOD;
    ans -= c(n, i);
  }
  cout << (ans % MOD + MOD) % MOD;
  // vector<vector<long long>> dp(n + 1, vector<long long>(m + 2));
  // dp[1][1] = 1;
  // for (int i = 2; i <= n; i++)
  //   for (int j = 0; j <= m; j++) {
  //     dp[i][j] = ((j ? dp[i - 1][j - 1] : 0) + dp[i - 1][j + 1]) % MOD;
  //   }
  // long long ans = 0;
  // for (auto x : dp[n]) ans += x;
  // cout << ans % MOD;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  jc[0] = 1;
  for (int i = 1; i < MAXN; i++) jc[i] = i * jc[i - 1] % MOD;
  invjc[MAXN - 1] = inv(jc[MAXN - 1]);
  for (int i = MAXN - 1; i >= 1; i--) invjc[i - 1] = i * invjc[i] % MOD;
  int t = 1;
  // cin>>t;
  while (t--) solve();
  return 0;
}

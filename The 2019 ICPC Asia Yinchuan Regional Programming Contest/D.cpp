/*
 * author: zhaoyiping
 * time: 2023-03-08 19:31:14
 */
#include <bits/stdc++.h>

#include <string>
using namespace std;
const int MAXN = 1e5 + 5;
const long long MOD = 93257 * 643;
const long long phi = 93256 * 642;
long long powm(long long a, long long b, long long mod = MOD) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return ret;
}
long long bpow(long long a, long long b, bool big) {
  if (__gcd(a, MOD) == 1) return powm(a, b % phi, MOD);
  if (big || b >= phi) {
    b %= phi;
    b += phi;
  }
  return powm(a, b, MOD);
}
long long f[MAXN];
long long sum[MAXN];
long long jc[MAXN];
long long sumk[MAXN];
void solve() {
  string n;
  int m, k, d;
  cin >> n >> m >> d >> k;
  long long nn = 0;
  bool big = false;
  if (n.size() <= 10) {
    nn = stoll(n);
  } else {
    for (auto x : n) {
      nn = (nn * 10 + x - '0') % phi;
    }
    big = true;
  }
  long long nk = nn * k;
  for (int i = 1; i <= m; i++) {
    sum[i] = (sum[i - 1] + bpow(i, nk, big)) % MOD;
    sumk[i] = (sumk[i - 1] + powm(i, k)) % MOD;
  }
  memset(f, -1, sizeof f);
  std::function<long long(int)> cal = [&](int m) {
    if (~f[m]) return f[m];
    long long ans = 0;
    ans = bpow(sumk[m], nn, big);
    for (int i = 2; i <= m; i++) {
      long long xx = m / i;
      long long r = m / xx;
      ans -= (sum[r] - sum[i - 1] + MOD) * cal(xx) % MOD;
      i = r;
    }
    ans %= MOD;
    if (ans < 0) ans += MOD;
    return f[m] = ans;
  };
  cout << bpow(d, nk, big) * cal(m / d) % MOD << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  jc[0] = 1;
  for (int i = 1; i < MAXN; i++) jc[i] = i * jc[i - 1] % MOD;
  cin >> t;
  while (t--) solve();
  return 0;
}

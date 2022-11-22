/*
 * author: zhaoyiping
 * time: 2022-11-20 14:22:34
 */
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 19;
const int MOD = 1e9 + 7;
long long sum0[MAXN];
long long nmax;
long long n, m, k;
long long jc[MAXN];
long long invjc[MAXN];
long long powm(long long a, long long b) {
  a %= MOD;
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return ret;
}
long long inv(long long x) { return powm(x, MOD - 2); }
long long c[MAXN][MAXN];
void init() {
  vector<int> v(k);
  for (int i = 0; i < v.size(); i++) {
    v[i] = 1;
    for (int j = 0; j < v.size(); j++)
      for (int k = j + 1; k < v.size(); k++) sum0[i + 1] += (v[j] ^ v[k]);
    nmax = max(nmax, sum0[i + 1]);
  }
  jc[0] = 1;
  for (int i = 1; i <= k; i++) jc[i] = jc[i - 1] * i % MOD;
  invjc[k] = inv(jc[k]);
  for (int i = k; i >= 1; i--) invjc[i - 1] = i * invjc[i] % MOD;
  for (int i = 0; i <= k; i++)
    for (int j = 0; j <= i; j++)
      c[i][j] = jc[i] * invjc[j] % MOD * invjc[i - j] % MOD;
}
map<long long, long long> cache[50][50];
int raw[50];
long long cal(int now, int cnt, long long n) {
  if (n < 0) return 0;
  if (now == -1) return n == 0;
  if ((nmax << (now + 1)) < n) return 0;
  if (cache[now][cnt].count(n)) return cache[now][cnt][n];
  long long ret = 0;
  for (int i = 0; i <= k; i++) {
    if (raw[now] == 0) {
      if (i > k - cnt) break;
      (ret += c[k - cnt][i] * cal(now - 1, cnt, n - (sum0[i] << now))) %= MOD;
    } else {
      // i 1
      for (int j = 0; j <= i && j <= cnt; j++) {
        // j come from cnt
        ret += c[cnt][j] * c[k - cnt][i - j] % MOD *
               cal(now - 1, j, n - (sum0[i] << now));
        ret %= MOD;
      }
    }
  }
  return cache[now][cnt][n] = ret;
}
void solve() {
  cin >> n >> m >> k;
  init();
  int i;
  for (i = 0; (1ll << i) <= m; i++) {
    if (m & (1ll << i))
      raw[i] = 1;
    else
      raw[i] = 0;
  }
  cout << cal(i, k, n);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  // cin>>t;
  while (t--) solve();
  return 0;
}
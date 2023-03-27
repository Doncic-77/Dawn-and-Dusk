/*
 * author: zhaoyiping
 * time: 2023-03-18 10:01:38
 */
#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
using namespace std;
template <int N, int M>
class Matrix {
 public:
  using T = array<array<long long, M>, N>;
  T v;
  void zero() {
    for (auto &x : v) fill(x.begin(), x.end(), 0);
  }
  void one() {
    static_assert(N == M);
    zero();
    for (int i = 0; i < N; i++) v[i][i] = 1;
  }
  Matrix() { zero(); }
  Matrix(T tmp) : v(tmp) {}
  array<long long, M> &operator[](int x) { return v[x]; }
  const array<long long, M> &operator[](int x) const { return v[x]; }
};
template <int N, int M, int K>
Matrix<N, M> operator*(const Matrix<N, K> &a, const Matrix<K, M> &b) {
  Matrix<N, M> ret;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      for (int k = 0; k < K; k++) ret[i][j] += a[i][k] * b[k][j];
  return ret;
}
template <int N, int M>
Matrix<N, M> operator+(const Matrix<N, M> &a, const Matrix<N, M> &b) {
  Matrix<N, M> ret;
  for (int i = 0; i < a.n; i++)
    for (int j = 0; j < a.m; j++) {
      ret[i][j] = a[i][j] + b[i][j];
    }
  return ret;
}
int cal(int n) {
  map<int, map<int, int>> ma;
  ma[0].insert({0, 0});
  queue<array<int, 2>> q;
  q.push({0, 0});
  while (q.size()) {
    auto now = q.front();
    q.pop();
    if (ma[now[0]][now[1]] == n) break;
    for (int i = -2; i <= 2; i++)
      for (int j = -2; j <= 2; j++) {
        if (abs(i) == abs(j)) continue;
        if (i == 0 || j == 0) continue;
        if (ma[now[0] + i].count(now[1] + j)) continue;
        ma[now[0] + i][now[1] + j] = ma[now[0]][now[1]] + 1;
        q.push({now[0] + i, now[1] + j});
      }
  }
  int ans = 0;
  for (auto &x : ma) ans += x.second.size();
  return ans;
}
vector<long long> v;
Matrix<3, 3> mul(array<array<long long, 3>, 3>{
    array<long long, 3>{3, -3, 1}, {1, 0, 0}, {0, 1, 0}});
template <int N>
Matrix<N, N> pow(Matrix<N, N> a, int b) {
  Matrix<N, N> ret(a);
  ret.one();
  while (b) {
    if (b & 1) ret = ret * a;
    a = a * a;
    b >>= 1;
  }
  return ret;
}
void solve() {
  unsigned long long n;
  cin >> n;
  if (n < 10) {
    cout << v[n] << "\n";
    return;
  }
  cout << 14 * n * n - 6 * n + 5 << "\n";
  // Matrix<3, 1> raw(
  //     array<array<long long, 1>, 3>{array<long long, 1>{v[9]}, {v[8]},
  //     {v[7]}});
  // n -= 9;
  // auto t = pow(mul, n) * raw;
  // cout << t[0][0] << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  v.resize(20);
  for (int i = 0; i < v.size(); i++) v[i] = cal(i);
  for (int i = 3; i < v.size(); i++)
    cerr << v[i] - 3 * v[i - 1] + 3 * v[i - 2] - v[i - 3] << endl;
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
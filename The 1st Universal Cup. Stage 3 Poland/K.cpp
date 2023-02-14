/*
 * author: zhaoyiping
 * time: 2023-02-11 13:28:51
 */
#include <bits/stdc++.h>

#include <cassert>
using namespace std;
void no() { cout << "NIE\n"; }
void yes() { cout << "TAK\n"; }
void out(array<int, 2> v) { cout << v[0] + 1 << " " << v[1] + 1 << "\n"; }
void out(const vector<string> &v, char c) {
  vector<array<int, 2>> a, b;
  for (int i = 0; i < v.size(); i++)
    for (int j = 0; j < v[i].size(); j++)
      if (v[i][j] == 'o')
        a.push_back({i, j});
      else if (v[i][j] == 'x')
        b.push_back({i, j});
  if (a.size() == b.size()) {
    if (c == 'x') swap(a, b);
  } else if (a.size() < b.size()) {
    assert(c == 'x');
    swap(a, b);
  }
  while (a.size()) {
    out(a.back());
    a.pop_back();
    if (b.size()) {
      out(b.back());
      b.pop_back();
    }
  }
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<string> v(n);
  for (auto &x : v) cin >> x;
  auto count = [&](char c) {
    int cnt = 0;
    for (auto &x : v)
      for (auto y : x)
        if (y == c) cnt++;
    return cnt;
  };
  auto valid = [&](int x, int y) { return x >= 0 && x < n && y >= 0 && y < n; };
  auto check = [&](int x, int y, int f, char c) {
    static const int nmove[][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};
    for (int i = 0; i < k; i++) {
      int nx = x + nmove[f][0] * i;
      int ny = y + nmove[f][1] * i;
      if (valid(nx, ny) && v[nx][ny] == c) continue;
      return false;
    }
    return true;
  };
  auto win_count = [&]() {
    int cnt = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        for (int k = 0; k < 4; k++)
          if (v[i][j] != '.' && check(i, j, k, v[i][j])) cnt++;
    return cnt;
  };
  int a = count('x'), b = count('o');
  if (abs(a - b) > 1) return no();
  if (win_count() == 0) {
    if (a + b == n * n) {
      yes();
      if (a > b)
        out(v, 'x');
      else
        out(v, 'o');
    } else {
      no();
    }
    return;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (v[i][j] == '.') continue;
      char c = v[i][j];
      v[i][j] = '.';
      if (c == 'x')
        a--;
      else
        b--;
      if (abs(a - b) > 1 || win_count()) {
        v[i][j] = c;
        if (c == 'x')
          a++;
        else
          b++;
        continue;
      }
      yes();
      out(v, a == b ? c : "xo"[c == 'x']);
      out({i, j});
      return;
    }
  no();
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}

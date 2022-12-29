
/*
 * author: zhaoyiping
 * time: 2022-12-16 13:50:39
 */
#include <bits/stdc++.h>

#include <cstdlib>
using namespace std;
void ask(int a, int b) {
  cout << a << " " << b << endl;
  string s;
  if (s == "WIN") exit(0);
}
void solve() {
  int n;
  cin >> n;
  // n-1 次
  auto sort1 = [&]() {
    for (int i = 1; i < n; i++) {
      ask(i, i + 1);
    }
  };
  auto useless = [&](int n) {
    while (n--) {
      ask(1, 2);
    }
  };
  sort1();
  sort1();
  useless(2);
  int sorted = n - 1;
  while (sorted > 1) {
    string s;
    for (int i = n; i > sorted; i--) {
      ask(i - 1, i);
    }
    for (int i = 1; i < sorted; i++) {
      ask(i, i + 1);
    }
    // n-1次
    sort1();
    useless(2);
    sorted--;
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
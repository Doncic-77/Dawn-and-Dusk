/*
 * author: zhaoyiping
 * time: 2023-03-11 13:16:04
 */
#include <bits/stdc++.h>

#include <cassert>
using namespace std;
void inv(list<string>& l) {
  l.push_back("atan");
  l.push_back("sin");
  l.push_back("acos");
  l.push_back("tan");
}
void f3(list<string>& l) {
  l.push_back("atan");
  l.push_back("sin");
}
void f5(list<string>& l) {
  l.push_back("atan");
  l.push_back("sin");
  l.push_back("acos");
  l.push_back("sin");
}
void f6(list<string>& l) {
  f5(l);
  inv(l);
}
list<string> cal(int aa, int bb) {
  if (aa == 0) return {};
  if (aa == bb) return {"cos"};
  list<string> ret;
  if (aa > bb) {
    ret = cal(aa - bb, bb);
    f6(ret);
  } else {
    ret = cal(bb, aa);
    inv(ret);
  }
  return ret;
}
void solve() {
  int a, b;
  cin >> a >> b;
  auto ans = cal(a * a, b * b);
  cout << ans.size() << endl;
  for (auto x : ans) cout << x << " ";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  // cin>>t;
  while (t--) solve();
  return 0;
}

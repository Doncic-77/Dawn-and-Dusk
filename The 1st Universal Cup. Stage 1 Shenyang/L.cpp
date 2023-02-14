/*
 * author: zhaoyiping
 * time: 2023-01-28 13:35:47
 */
#include <bits/stdc++.h>

#include <iomanip>
using namespace std;
class pp {
 public:
  int hp;
  int atk;
};
class answer {
 public:
  double win = 0, lose = 0, tie = 0;
};
answer operator+(const answer &a, const answer &b) {
  return {.win = a.win + b.win, .lose = a.lose + b.lose, .tie = a.tie + b.tie};
}
vector<pp> clear(const vector<pp> &a) {
  vector<pp> ret;
  for (auto x : a)
    if (x.hp > 0) ret.push_back(x);
  return ret;
}
answer dfs(int now, array<vector<pp>, 2> &a, array<vector<int>, 2> &att,
           double p) {
  int count[2] = {0, 0};
  for (int i = 0; i < 2; i++)
    for (const auto &t : a[i])
      if (t.hp > 0) count[i]++;
  if (count[0] == 0 && count[1] == 0) return {.tie = p};
  if (count[0] == 0) return {.lose = p};
  if (count[1] == 0) return {.win = p};
  int cc = count[1 - now];
  answer ret;
  int tt = -1;
  for (int i = 0; i < a[now].size(); i++) {
    if (a[now][i].hp <= 0) continue;
    if (tt == -1 || att[now][i] < att[now][tt]) tt = i;
  }
  auto &aa = a[now][tt];
  att[now][tt]++;
  for (int j = 0; j < a[1 - now].size(); j++) {
    auto &bb = a[1 - now][j];
    if (bb.hp <= 0) continue;
    aa.hp -= bb.atk;
    bb.hp -= aa.atk;
    ret = ret + dfs(1 - now, a, att, p / cc);
    aa.hp += bb.atk;
    bb.hp += aa.atk;
  }
  att[now][tt]--;
  return ret;
}
// answer dfs(int now, int tt, array<vector<pp>, 2> &a, double p) {
//   if (tt == a[now].size()) {
//     array<vector<pp>, 2> b;
//     for (int i = 0; i < 2; i++) b[i] = clear(a[i]);
//     if (b[0].empty() && b[1].empty()) return {.tie = p};
//     if (b[0].empty()) return {.lose = p};
//     if (b[1].empty()) return {.win = p};
//     return dfs(1 - now, 0, b, p);
//   }
//   auto &aa = a[now];
//   auto &bb = a[1 - now];
//   answer ret;
//   int count = 0;
//   for (int i = 0; i < bb.size(); i++) {
//     if (bb[i].hp > 0) count++;
//   }
//   if (count == 0) return dfs(now, tt + 1, a, p);
//   for (int i = 0; i < bb.size(); i++) {
//     if (bb[i].hp <= 0) continue;
//     bb[i].hp -= aa[tt].atk;
//     aa[tt].hp -= bb[i].atk;
//     // auto tmp = dfs(now, tt + 1, a, p / bb.size());
//     auto tmp = dfs(now, tt + 1, a, p / count);
//     ret = ret + tmp;
//     bb[i].hp += aa[tt].atk;
//     aa[tt].hp += bb[i].atk;
//   }
//   return ret;
// }
void solve() {
  int n, m;
  cin >> n >> m;
  vector<pp> a(n), b(m);
  for (auto &x : a) {
    cin >> x.hp;
    x.atk = x.hp;
  }
  for (auto &x : b) {
    cin >> x.hp;
    x.atk = x.hp;
  }
  answer aa;
  array<vector<pp>, 2> vv = {a, b};
  array<vector<int>, 2> att;
  att[0].resize(n);
  att[1].resize(m);
  if (n > m)
    aa = dfs(0, vv, att, 1);
  else if (n < m)
    aa = dfs(1, vv, att, 1);
  else
    aa = dfs(0, vv, att, 0.5) + dfs(1, vv, att, 0.5);
  cout << fixed << setprecision(12);
  cout << aa.win << "\n";
  cout << aa.lose << "\n";
  cout << aa.tie << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  // cin>>t;
  while (t--) solve();
  return 0;
}

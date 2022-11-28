#include <bits/stdc++.h>
using namespace std;
string ss[] = {"Monday", "Tuesday",  "Wednesday", "Thursday",
               "Friday", "Saturday", "Sunday"};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  map<string, int> days;
  for (int i = 0; i < 7; i++) days[ss[i]] = i + 1;
  vector<vector<int>> emplyees(n);
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    emplyees[i].resize(t);
    string s;
    for (auto &x : emplyees[i]) {
      cin >> s;
      x = days[s];
    }
  }
  vector<int> h(m);
  for (auto &x : h) cin >> x;
  reverse(h.begin(), h.end());
  vector<vector<int>> ps(k);
  for (auto &x : ps) {
    int t;
    cin >> t;
    x.resize(t);
    for (auto &y : x) cin >> y, y--;
    reverse(x.begin(), x.end());
  }
  vector<set<int>> todo(n);
  vector<int> cando(n);
  set<int> cds[8];
  vector<int> ans(k);
  auto apply = [&](int x, int y) {
    todo[x].insert(y);
    if (++cando[x] == 1) {
      for (auto t : emplyees[x]) cds[t].insert(x);
    }
  };
  auto done = [&](int x, int y, int day) {
    todo[x].erase(y);
    if (--cando[x] == 0) {
      for (auto t : emplyees[x]) cds[t].erase(x);
    }
    ps[y].pop_back();
  };
  for (int i = 0; i < k; i++) {
    apply(ps[i].back(), i);
  }
  int finish = 0;
  for (int i = 1; finish < k; i++) {
    if (h.size() && i == h.back()) {
      h.pop_back();
      continue;
    }
    int t = (i - 1) % 7 + 1;
    vector<int> dd;
    auto p = cds[t];
    for (auto x : p) {
      assert(todo[x].size());
      int d = *todo[x].begin();
      done(x, d, i);
      dd.push_back(d);
    }
    for (auto x : dd) {
      if (ps[x].size())
        apply(ps[x].back(), x);
      else
        ans[x] = i, finish++;
    }
  }
  for (auto x : ans) cout << x << " ";
  return 0;
}
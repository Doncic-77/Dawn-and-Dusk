/*
 * author: zhaoyiping
 * time: 2022-12-16 13:13:19
 */
#include <bits/stdc++.h>

#include <algorithm>
#include <cmath>

using namespace std;
const int MAXN = 1e6 + 5;
void no() {
  cout << "No\n";
  exit(0);
}
class e {
 public:
  int v;
  int w;
  int next;
} edge[MAXN];
int head[MAXN];
bool vis[MAXN];
vector<int> ans;
int num;
void add_edge(int u, int v, int w) {
  num++;
  edge[num] = e{.v = v, .w = w, .next = head[u]};
  head[u] = num;
}
void add(int u, int v, int w) {
  add_edge(u, v, w);
  // add_edge(u, v, -w);
}
void dfs(int u) {
  for (auto &i = head[u]; i != 0; i = edge[i].next) {
    int v = edge[i].v;
    int w = edge[i].w;
    if (vis[abs(w)]) continue;
    vis[abs(w)] = 1;
    dfs(v);
    ans.push_back(w);
  }
}
void solve() {
  int n, c;
  cin >> n >> c;
  vector<array<int, 3>> v(n);
  vector<int> tt;
  tt.push_back(c);
  for (auto &x : v) {
    for (auto &y : x) cin >> y;
    tt.push_back(x[0]);
    tt.push_back(x[1]);
  }
  sort(tt.begin(), tt.end());
  tt.erase(unique(tt.begin(), tt.end()), tt.end());
  auto getidx = [&](int x) {
    return lower_bound(tt.begin(), tt.end(), x) - tt.begin();
  };
  for (auto &x : v) {
    x[0] = getidx(x[0]);
    x[1] = getidx(x[1]);
  }
  map<int, vector<int>> vv;
  vector<int> in(tt.size()), out(tt.size());
  for (int i = 0; i < n; i++) {
    auto &x = v[i];
    if (x[2]) {
      add(x[0], x[1], i);
      out[x[0]]++;
      in[x[1]]++;
    } else
      vv[x[0]].push_back(i);
  }
  int cnt = 0;
  for (int i = 0; i < tt.size(); i++) {
    if (in[i] == out[i]) continue;
    if (in[i] == out[i] + 1)
      cnt++;
    else if (in[i] == out[i] - 1) {
      if (c != tt[i]) no();
    } else {
      no();
    }
  }
  c = getidx(c);
  if (cnt > 1) no();
  dfs(c);
  vector<int> aans;
  int now = c;
  auto pushv = [&]() {
    for (auto &x : vv) {
      if (x.first != now) {
        for (auto x : x.second) aans.push_back(x);
      }
    }
    for (auto it = vv.begin(); it != vv.end();) {
      if (it->first != now)
        it = vv.erase(it);
      else
        it++;
    }
  };
  for (int i = (int)ans.size() - 1; i >= 0; i--) {
    pushv();
    aans.push_back(ans[i]);
    now = v[ans[i]][1];
  }
  pushv();
  if (aans.size() == n) {
    cout << "Yes\n";
    for (auto x : aans) cout << x + 1 << " ";
  } else
    no();
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  // cin>>t;
  while (t--) solve();
  return 0;
}
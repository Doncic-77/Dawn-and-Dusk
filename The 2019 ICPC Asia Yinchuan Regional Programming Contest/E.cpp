/*
 * author: zhaoyiping
 * time: 2023-03-08 22:05:40
 */
#include <bits/stdc++.h>

#include <algorithm>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
const int MAXN = 1e5 + 5;
int f[MAXN];
vector<int> g[MAXN];
unsigned long long ans[MAXN];
__gnu_pbds::priority_queue<pair<int, int>, less<pair<int, int>>,
                           __gnu_pbds::binomial_heap_tag>
    pqs[MAXN];
class node {
 public:
  vector<vector<int>> a;
  array<int, 30> b;
  node() {
    a.resize(30);
    for (int i = 0; i < 30; i++) a[i].resize(30 - i);
    fill(b.begin(), b.end(), 0);
  }
  vector<int> geta(int x) {
    vector<int> v;
    for (int i = 0; i < 30; i++)
      if (x & (1 << i)) v.push_back(i);
    return v;
  }
  void add(int x) {
    auto v = geta(x);
    for (int i = 0; i < v.size(); i++) {
      for (int j = i + 1; j < v.size(); j++) {
        a[v[i]][v[j] - v[i] - 1]++;
      }
      b[v[i]]++;
    }
  }
  void remove(int x) {
    auto v = geta(x);
    for (int i = 0; i < v.size(); i++) {
      for (int j = i + 1; j < v.size(); j++) {
        a[v[i]][v[j] - v[i] - 1]--;
      }
      b[v[i]]--;
    }
  }
};
node operator+(const node& a, const node& b) {
  node ret;
  for (int i = 0; i < 30; i++)
    for (int j = 0; j < 30 - i; j++) ret.a[i][j] = a.a[i][j] + b.a[i][j];
  for (int i = 0; i < 30; i++) ret.b[i] = a.b[i] + b.b[i];
  return ret;
}
int deep[MAXN];
int k;
node dfs(int now, int fa) {
  deep[now] = deep[fa] + 1;
  pqs[now].push({deep[now], now});

  node ret;
  ret.add(f[now]);
  for (auto x : g[now])
    if (x != fa) {
      ret = ret + dfs(x, now);
      pqs[now].join(pqs[x]);
    }
  while (pqs[now].size() && pqs[now].top().first > deep[now] + k) {
    auto x = pqs[now].top().second;
    pqs[now].pop();
    ret.remove(f[x]);
  }
  int n = pqs[now].size();
  for (int i = 0; i < 30; i++)
    for (int j = i + 1; j < 30; j++) {
      ans[now] += (2ull << (i + j)) * (ret.b[i] - ret.a[i][j - i - 1]) *
                  (ret.b[j] - ret.a[i][j - i - 1]);
      int t = n - ret.b[i] - ret.b[j] + ret.a[i][j - i - 1];
      ans[now] += (2ull << (i + j)) * t * ret.a[i][j - i - 1];
    }
  for (int i = 0; i < 30; i++)
    ans[now] += (1ull << (i + i)) * (n - ret.b[i]) * ret.b[i];
  return ret;
}
void solve() {
  int n;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> f[i];
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    g[i].push_back(x);
    g[x].push_back(i);
  }
  dfs(1, 0);
  for (int i = 1; i <= n; i++) cout << ans[i] << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  // cin>>t;
  while (t--) solve();
  return 0;
}

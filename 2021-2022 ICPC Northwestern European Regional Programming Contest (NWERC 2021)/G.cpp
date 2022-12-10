/*
 * author: zhaoyiping
 * time: 2022-12-10 13:53:36
 */
#include <bits/stdc++.h>

#include <algorithm>
#include <ctime>
#include <numeric>
using namespace std;
const int MAXN = 5005;
void solve() {
  int n, w;
  cin >> n >> w;
  vector<string> v(n);
  for (auto &x : v) cin >> x;
  sort(v.begin(), v.end());
  vector<int> dp(n);
  auto getdp = [&](int x) {
    dp[0] = v[0].size();
    for (int i = 1; i < n; i++) {
      dp[i] = w + 1;
      int maxlen = 0;
      for (int j = i; j >= 0 && (i - j + 1) <= x; j--) {
        maxlen = max(maxlen, (int)v[j].size());
        if (j == 0) {
          dp[i] = min(dp[i], maxlen);
        } else {
          dp[i] = min(dp[i], dp[j - 1] + maxlen + 1);
        }
      }
    }
  };
  auto check = [&](int x) -> bool {
    getdp(x);
    return dp.back() <= w;
    return false;
  };
  int l = 1, r = n;
  while (l < r) {
    int mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  getdp(l);
  int rr = l;
  int cc = dp.back();
  vector<pair<int, int>> ccans;
  for (int i = n - 1; i >= 0; i--) {
    int maxlen = 0;
    for (int j = i; j >= 0 && (i - j + 1) <= l; j--) {
      maxlen = max(maxlen, (int)v[j].size());
      if (j == 0) {
        ccans.push_back({j, i});
        i = j;
        break;
      } else {
        if (cc <= maxlen + 1) continue;
        if (dp[j - 1] + maxlen + 1 == cc) {
          cc -= maxlen + 1;
          ccans.push_back({j, i});
          i = j;
          break;
        }
      }
    }
  }
  vector<int> ccs(ccans.size());
  reverse(ccans.begin(), ccans.end());
  cout << rr << " ";
  cout << ccans.size() << "\n";
  for (int j = 0; j < ccs.size(); j++) {
    for (int i = ccans[j].first; i <= ccans[j].second; i++) {
      ccs[j] = max(ccs[j], (int)v[i].size());
    }
    cout << ccs[j] << " ";
  }
  cout << "\n";
  auto outputspace = [](int x) {
    while (x--) cout << " ";
  };
  for (int i = 0; i < rr; i++) {
    for (int j = 0; j < ccs.size(); j++) {
      auto &x = ccans[j];
      if (x.first > x.second) {
        outputspace(ccs[j] + 1);
      } else {
        cout << v[x.first];
        outputspace(ccs[j] + 1 - v[x.first++].size());
      }
    }
    cout << "\n";
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
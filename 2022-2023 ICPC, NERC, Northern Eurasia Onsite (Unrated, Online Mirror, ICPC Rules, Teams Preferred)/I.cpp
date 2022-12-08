/*
 * author: zhaoyiping
 * time: 2022-12-07 16:29:03
 */
#include <bits/stdc++.h>

#include <algorithm>
#include <array>
#include <cstdlib>
#include <numeric>
using namespace std;
const int MAXN = 5982;
class big {
 public:
  vector<int> v;
  big(int x = 0) {
    while (x) {
      v.push_back(x % 10);
      x /= 10;
    }
  }
};
big zero() { return big(0); }
big operator+(const big& a, const big& b) {
  vector<int> tmp(max(a.v.size(), b.v.size()) + 1);
  for (int i = 0; i + 1 < tmp.size(); i++) {
    tmp[i] += a.v[i] + b.v[i];
    tmp[i + 1] += tmp[i] / 10;
    tmp[i] %= 10;
  }
  big ret;
  tmp.swap(ret.v);
  return ret;
}
big operator*(const big& a, int x) {
  vector<int> v;
  int pre = 0;
  for (auto xx : a.v) {
    pre += xx * x;
    v.push_back(pre % 10);
    pre /= 10;
  }
  while (pre) {
    v.push_back(pre % 10);
    pre /= 10;
  }
  big ret;
  ret.v = v;
  return ret;
}
big facts[5983];
// class node {
//  public:
//   int ans;
//   int xx;
//   node* v[10];
//   node() { ans = xx = 0; }
// };
// node* root;
// int dd;
// node* build(const vector<int>& v, int deep) {
//   if (v.empty()) return nullptr;
//   if (v.size() == 1) {
//     node* ret = new node;
//     ret->ans = v[0];
//     return ret;
//   }
//   dd = max(dd, deep);
//   int nmax = facts[v.back()].v.size();
//   vector<array<int, 10>> vv;
//   for (int i = 0; i < nmax; i++) {
//     array<int, 10> tmp;
//     int tt = 0;
//     for (auto x : v) {
//       if (facts[x].v.size() <= i) {
//         tmp[0]++;
//         tt++;
//       } else {
//         tmp[facts[x].v[i]]++;
//       }
//     }
//     if (tt > v.size() / 2) break;
//     vv.push_back(tmp);
//   }
//   auto cmp = [&](const array<int, 10>& a, const array<int, 10>& b) {
//     return *max_element(a.begin(), a.end()) < *max_element(b.begin(),
//     b.end());
//   };
//   int t = min_element(vv.begin(), vv.end(), cmp) - vv.begin();
//   array<vector<int>, 10> tt;
//   for (auto x : v) {
//     if (facts[x].v.size() <= t) {
//       tt[0].push_back(x);
//     } else {
//       tt[facts[x].v[t]].push_back(x);
//     }
//   }
//   node* ret = new node;
//   ret->xx = t;
//   for (int i = 0; i < 10; i++) {
//     ret->v[i] = build(tt[i], deep + 1);
//   }
//   return ret;
// }
array<vector<int>, 10> tmp;
int tp;
pair<int, array<vector<int>, 10>> getnmax(const vector<int>& v) {
  int nmax = facts[v.back()].v.size();
  vector<array<int, 10>> vv;
  for (int i = 0; i < nmax; i++) {
    array<int, 10> tmp;
    fill(tmp.begin(), tmp.end(), 0);
    int tt = 0;
    for (auto x : v) {
      if (facts[x].v.size() <= i) {
        tmp[0]++;
        tt++;
      } else {
        tmp[facts[x].v[i]]++;
      }
    }
    if (tt > v.size() / 2) break;
    vv.push_back(tmp);
    if (*max_element(tmp.begin(), tmp.end()) <= v.size() / 5) break;
  }
  auto cmp = [&](const array<int, 10>& a, const array<int, 10>& b) {
    return *max_element(a.begin(), a.end()) < *max_element(b.begin(), b.end());
  };
  int t = min_element(vv.begin(), vv.end(), cmp) - vv.begin();
  array<vector<int>, 10> tt;
  for (auto x : v) {
    if (facts[x].v.size() <= t) {
      tt[0].push_back(x);
    } else {
      tt[facts[x].v[t]].push_back(x);
    }
  }
  return {t, tt};
}
void init() {
  facts[0] = 1;
  for (int i = 1; i <= MAXN; i++) {
    // if (i % 100 == 0) cerr << i << endl;
    facts[i] = facts[i - 1] * i;
  }
  vector<int> v(5982);
  iota(v.begin(), v.end(), 1);
  // cerr << "shit" << endl;
  // root = build(v, 0);
  // cerr << dd << endl;
  auto pp = getnmax(v);
  tmp = pp.second;
  tp = pp.first;
}
int ask(int x) {
  // cerr << "ask " << x << endl;
  cout << "? " << x << endl;
  cin >> x;
  // cerr << "get " << x << endl;
  return x;
}
void answer(int x) {
  // cerr << "answer " << x << endl;
  cout << "! " << x << endl;
  string s;
  cin >> s;
  if (s != "YES") {
    exit(0);
  }
  return;
}
void solve() {
  vector<int> now = tmp[ask(tp)];
  for (int i = 0; i < 10; i++) {
    // cerr << "round " << i << " size " << now.size() << endl;
    if (now.size() == 1 || i == 9) {
      answer(now[0]);
      return;
    }
    auto pp = getnmax(now);
    // cerr << pp.first << endl;
    now = pp.second[ask(pp.first)];
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  init();
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}

#include <bits/stdc++.h>

#include <cassert>
#include <cstdio>
using namespace std;
int m;
enum score_type {
  kAccept,
  kIgnore,
  kWa,
  kSubmitInLastHour,
};
struct accept {
  int fail;
  int t;
};
struct wa {
  int t;
};
struct submit_in_last_hour {
  int before;
  int aftre;
};
class score {
 public:
  score_type type;
  union {
    accept a;
    submit_in_last_hour s;
    wa w;
  } t;
};
int cal(int ac, int t, vector<array<int, 2>> v) {
  for (int i = 0; i < (1 << v.size()); i++) {
    if (__builtin_popcount(i) != ac) continue;
    int lb = 0;
    int cnt = 0;
    for (int j = 0; j < v.size(); j++) {
      if (i & (1 << j)) {
        lb += v[j][0];
        cnt += v[j][1];
      }
    }
    if (t >= lb && lb + cnt * 20 + ac * 59 >= t) {
      return i;
    }
  }
  return -1;
}
void print(vector<score> v) {
  cout << "Yes\n";
  for (int i = 0; i < m; i++) {
    if (v[i].type == kIgnore) {
      cout << ".\n";
    } else if (v[i].type == kAccept) {
      auto t = v[i].t.a;
      cout << "+ " << t.fail << "/" << t.t << "\n";
    } else if (v[i].type == kWa) {
      auto t = v[i].t.w;
      cout << "- " << t.t << "\n";
    } else {
      assert(false);
    }
  }
}
void solve() {
  int a, b;
  cin >> a >> b;
  vector<score> v(m);
  int now = 0;
  int nowt = 0;
  int pd = 0;
  for (int i = 0; i < m; i++) {
    char c;
    cin >> c;
    if (c == '.')
      v[i].type = kIgnore;
    else if (c == '-') {
      int x;
      cin >> x;
      v[i].type = kWa;
      v[i].t.w.t = x;
    } else if (c == '+') {
      int x, y;
      cin >> x >> c >> y;
      v[i].type = kAccept;
      v[i].t.a.t = y;
      v[i].t.a.fail = x;
      now++;
      nowt += y + (x - 1) * 20;
    } else {
      int x, y;
      cin >> x >> y;
      v[i].type = kSubmitInLastHour;
      v[i].t.s = submit_in_last_hour{.before = y - x, .aftre = x};
      pd++;
    }
  }
  int diffnow = a - now;
  int difft = b - nowt;
  vector<array<int, 2>> vv;
  vector<int> raw;
  for (int i = 0; i < m; i++)
    if (v[i].type == kSubmitInLastHour) {
      auto t = v[i].t.s;
      vv.push_back({t.before * 20 + 240, min(100 - t.before, t.aftre - 1)});
      raw.push_back(i);
    }
  if (diffnow == 0) {
    if (difft == 0) {
      for (int i = 0; i < v.size(); i++) {
        if (v[i].type == kSubmitInLastHour) {
          v[i].type = kWa;
          v[i].t.w = wa{.t = v[i].t.s.before + v[i].t.s.aftre};
        }
      }
      print(v);
    } else {
      cout << "No\n";
    }
    return;
  }
  int tt = cal(diffnow, difft, vv);
  if (tt == -1) {
    cout << "No\n";
    return;
  }
  vector<int> fail(vv.size()), vt(vv.size());
  int lb = 0, cnt = 0;
  for (int i = 0; i < vv.size(); i++)
    if (tt & (1 << i)) {
      lb += vv[i][0];
      cnt += vv[i][1];
    }
  int need = min(cnt, (difft - lb) / 20);
  for (int i = 0; i < vv.size(); i++) {
    if (tt & (1 << i) && need > 0) {
      fail[i] = min(need, vv[i][1]);
      need -= fail[i];
      lb += fail[i] * 20;
    }
  }
  for (int i = 0; i < vv.size(); i++) {
    if (tt & (1 << i)) {
      vt[i] = min(59, difft - lb);
      lb += vt[i];
    }
  }
  assert(lb == difft);
  for (int i = 0; i < vv.size(); i++) {
    if (tt & (1 << i)) {
      v[raw[i]].type = kAccept;
      v[raw[i]].t.a =
          accept{.fail = v[raw[i]].t.s.before + fail[i] + 1, .t = vt[i] + 240};
    } else {
      v[raw[i]].type = kWa;
      v[raw[i]].t.w = wa{.t = v[raw[i]].t.s.before + v[raw[i]].t.s.aftre};
    }
  }
  print(v);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    solve();
  }
  return 0;
}
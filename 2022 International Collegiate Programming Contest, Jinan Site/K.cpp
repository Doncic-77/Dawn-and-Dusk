#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    set<int> se;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (!se.count(x + 1)) ans++;
      se.insert(x);
    }
    cout << ans << "\n";
  }
  return 0;
}
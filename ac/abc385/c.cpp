#include "bits/stdc++.h"
using namespace std;
#define int long long

#ifdef LOCAL
#include "lib/debug.h"
#define dbg(...)                                                               \
  cerr << "Line " << __LINE__ << ": " FOR_EACH_MACRO(out, __VA_ARGS__) << "\n"
#else
#define dbg(...) 69
#endif

const int mod = 1e9 + 7;

// #define googleOrFacebook
// #define testcases

void solve() {
  int n, i;
  cin >> n;
  vector<int> v(n);
  for (i = 0; i < n; i++) {
    cin >> v[i];
  }
  int ans = 1;
  for (int d = 1; d < n; d++) {
    set<int> vis;
    for (int i = 0; i < n; i++) {
      if (vis.count(i)) {
        continue;
      }
      int j = i;
      int lst = -1;
      int curr = 0;
      while (j < n) {
        if (v[j] == lst || lst == -1) {
          curr++;
        } else {
          ans = max(ans, curr);
          curr = 1;
        }
        ans = max(ans, curr);
        lst = v[j];
        vis.insert(j);
        j += d;
      }
    }
  }
  cout << ans;
  dbg("SEX");
}

signed main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int tt = 1, t = 1;
#ifdef testcases
  cin >> tt;
#endif
  while (t <= tt) {
#ifdef googleOrFacebook
    cout << "Case #" << t << ": ";
#endif
    solve();
    cout << "\n";
    t++;
  }
  return 0;
}
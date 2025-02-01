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
  int r;
  cin >> r;
  int ans = 1;
  for (int i = 0; i < r; i++) {
    // 1/2+i, 1/2+j
    //(1+2i)/2, (1+2j)/2
    //(1+4i2+4i)/4, (1+2j)2/4
    int lo = 0, hi = r, mid;
    int al = (1 + 4 * i * i + 4 * i);
    while (lo < hi) {
      mid = (lo + hi + 1) / 2;
      int be = (1 + 4 * mid * mid + 4 * mid);
      if (al + be > 4 * r * r) {
        hi = mid - 1;
      } else {
        lo = mid;
      }
    }
    ans += 4 * lo;
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
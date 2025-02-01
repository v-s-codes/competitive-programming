#include "bits/stdc++.h"
using namespace std;
#define int __int128

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
  long long n, i, m;
  cin >> n >> m;
  vector<long long> v(n);
  for (i = 0; i < n; i++) {
    cin >> v[i];
  }
  // sort(v.begin(), v.end());
  int lo = 0, hi = 1e18, mid;
  while (lo < hi) {
    mid = (lo + hi + 1) / 2;
    int tot = 0;
    for (int z : v) {
      //(z*(2k-1))<=mid k<=(mid+z)/2z
      int k = (mid + z) / (2 * z);
      tot += (k * k * z);
      // dbg((sig)log(k));
      if (tot > m || tot < 0) {
        hi = mid - 1;
        break;
      }
    }
    if (tot > m || tot < 0) {
      hi = mid - 1;
      continue;
    } else {
      lo = mid;
    }
  }
  int ans = 0;
  for (int z : v) {
    int k = (lo + z) / (2 * z);
    ans += k;
  }
  cout << ((long long)ans);
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
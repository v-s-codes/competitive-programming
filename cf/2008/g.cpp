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
#define testcases

void solve() {
  int n, i, k;
  cin >> n >> k;
  vector<int> v(n);
  int g = 0;
  for (i = 0; i < n; i++) {
    cin >> v[i];
    if (v[i]) {
      g = __gcd(g, v[i]);
    }
  }
  if (n == 1) {
    if (v[0] >= k) {
      cout << k - 1;
      return;
    }
    cout << k;
    return;
  }
  if (g == 1) {
    cout << n + k - 1;
    return;
  }
  if ((n - 1) * (g - 1) <= k) {
    cout << (n - 1) * g + (k - (n - 1) * (g - 1)) + 1;
    return;
  }
  cout << (k / (g - 1)) * g + (k % (g - 1)) + 1;

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
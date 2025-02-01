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

const int mod = 998244353;

#define googleOrFacebook
#define testcases

void solve() {
  int w, g, l;
  cin >> w >> g >> l;
  int x = (l + 1) % mod;
  (x *= x) %= mod;
  int y = l % mod;
  (y *= y) %= mod;
  int z = (x - y + mod) % mod;
  int diff = (w - g + mod) % mod;
  int ans = (diff * z) % mod;
  cout << ans;
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
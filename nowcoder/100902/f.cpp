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
int power(int x, int y) {
  int res = 1;
  x = x % mod;
  if (x == 0)
    return 0;
  while (y > 0) {
    if (y & 1)
      res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}
int inv(int n) { return power(n, mod - 2); }
void solve() {
  int n;
  cin >> n;
  vector<int> v(n + 5, 0), pre(n + 5, 0);
  v[0] = 0;
  v[1] = 0;
  for (int i = 2; i <= n; i++) {
    int al = pre[i - 2];
    (al *= 2) %= mod;
    (al *= inv(i - 1)) %= mod;
    (al += 1) %= mod;
    v[i] = al;
    pre[i] = (pre[i - 1] + v[i]) % mod;
  }
  cout << v[n];
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
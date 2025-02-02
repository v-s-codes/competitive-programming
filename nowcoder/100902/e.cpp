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
vector<int> fac;
void factorial(int n) {
  fac.clear();
  fac.resize(n + 1);
  fac[0] = 1;
  for (int i = 1; i <= n; i++) {
    fac[i] = (fac[i - 1] * i) % mod;
  }
}
vector<int> ifac;
void ifactorial(int n) {
  ifac.clear();
  ifac.resize(n + 1);
  for (int i = 0; i <= n; i++) {
    ifac[i] = inv(fac[i]);
  }
}
int ncr(int n, int r) {
  if (n < r)
    return 0;
  if (r == 0)
    return 1;
  return (((fac[n] * ifac[r]) % mod) * ifac[n - r]) % mod;
}
void solve() {
  int n, i;
  cin >> n;
  /*
     n/3
  ...||||||||..........
  .......||||||||||....
  'a    ''b ''c   ''a '
  b=2*(n/3)-(n/2)
  c=n/3-b
  a=n-(n/3)

  choose b indices and b nums and then arrange
  (n/3cb)*(n/3cb)*(b!)

  choose other indices for other c nums
  (acc)*(c!)

  a!
  */
  int d = n / 3;
  int e = n / 2;
  int b = 2 * d - e;
  int c = d - b;
  int a = n - d;
  int ans = 1;
  if (b < 0 || c < 0) {
    cout << 0;
    return;
  }
  (ans *= ncr(d, b)) %= mod;
  (ans *= ncr(d, b)) %= mod;
  (ans *= fac[b]) %= mod;
  (ans *= ncr(a, c)) %= mod;
  (ans *= fac[c]) %= mod;
  (ans *= fac[a]) %= mod;
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
  factorial(1000001);
  ifactorial(1000001);
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
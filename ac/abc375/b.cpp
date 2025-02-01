#include "bits/stdc++.h"
#include <iomanip>

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
  vector<pair<long double, long double>> v(n);
  for (i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  long double ans = 0;
  for (int i = 1; i < n; i++) {
    long double x = abs(v[i].first - v[i - 1].first);
    long double y = abs(v[i].second - v[i - 1].second);
    long double d = sqrtl(x * x + y * y);
    ans += d;
  }
  ans += sqrtl(v[0].first * v[0].first + v[0].second * v[0].second);
  ans += sqrtl(v[n - 1].first * v[n - 1].first +
               v[n - 1].second * v[n - 1].second);
  cout << fixed << setprecision(10) << ans;
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
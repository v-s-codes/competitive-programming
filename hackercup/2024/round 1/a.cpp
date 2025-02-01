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

#define googleOrFacebook
#define testcases

void solve() {
  int n, i;
  cin >> n;
  vector<pair<int, int>> v(n);
  for (i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  long double ans = 0;
  i = 1;
  for (auto z : v) {
    ans = max(ans, i / (long double)z.second);
    i++;
  }
  dbg(ans);
  i = 1;
  for (auto z : v) {
    if (i < z.first * ans) {
      cout << -1;
      return;
    }
    i++;
  }
  cout << setprecision(7) << ans;
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
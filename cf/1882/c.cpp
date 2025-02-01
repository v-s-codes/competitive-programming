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
  int n, i;
  cin >> n;
  vector<int> v(n);
  for (auto &z : v) {
    cin >> z;
  }
  if (v[0] >= 0) {
    int ans = 0;
    for (auto z : v)
      ans += max(0ll, z);
    cout << ans;
    return;
  }
  if (n == 1) {
    cout << 0;
    return;
  }
  if (v[1] <= 0) {
    int ans = 0;
    for (auto z : v)
      ans += max(0ll, z);
    cout << ans;
    return;
  }
  int ans = 0;
  for (auto z : v)
    ans += max(0ll, z);
  ans -= v[1];
  ans += max(0ll, v[0] + v[1]);
  cout << ans;
  return;
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
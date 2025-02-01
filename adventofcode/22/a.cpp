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

const int mod = 16777216;

// #define googleOrFacebook
// #define testcases

void solve() {
  vector<int> v;
  int x;
  while (cin >> x)
    v.push_back(x);
  int tot = 0;
  for (auto z : v) {
    for (int i = 0; i < 2000; i++) {
      auto m64 = z * 64;
      z = (m64 ^ z);
      z %= mod;
      auto d32 = z / 32;
      z = (z ^ d32);
      z %= mod;
      auto m2048 = z * 2048;
      z = (m2048 ^ z);
      z %= mod;
    }
    tot += z;
  }
  cout << tot;
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
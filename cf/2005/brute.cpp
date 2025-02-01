/*
ॐ भूर् भुवः स्वः । तत् सवितुर्वरेण्यं । भर्गो देवस्य धीमहि । धियो यो नः प्रचोदयात् ॥
*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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
  int n, m;
  cin >> n >> m;
  vector<string> vs(n);
  for (auto &i : vs)
    cin >> i;
  string x = "narek";
  int mx = 0;
  for (int i = 0; i < (1 << n); i++) {
    int j = 0;
    int tot = 0;
    for (int k = 0; k < n; k++) {
      if (i & (1 << k)) {
        for (auto &c : vs[k]) {
          if (c == x[j]) {
            j++;
            if (j == 5) {
              tot += 5;
              j = 0;
            }
          } else if (c == 'n' || c == 'a' || c == 'r' || c == 'e' || c == 'k') {
            tot--;
          }
        }
      }
      tot -= (j);
    }
    dbg(tot);
    mx = max(mx, tot);
    dbg(mx, i);
  }
  cout << mx;
}

signed main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  // #ifdef LOCAL
  //     freopen("input.txt", "r", stdin);
  //     freopen("output.txt", "w", stdout);
  // #endif
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
/*
ॐ भूर् भुवः स्वः । तत् सवितुर्वरेण्यं । भर्गो देवस्य धीमहि । धियो यो नः प्रचोदयात् ॥
*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
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
  int n;
  cin >> n;
  vector<pair<int, int>> vp;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    vp.push_back({x, y});
  }
  int ans = 0;
  set<map<int, int>> st;
  for (int i = 0; i < (1 << n); i++) {
    map<int, int> mp;
    auto br = 0;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        if (mp.count(vp[j].second)) {
          br = 1;
          break;
        }
        mp[vp[j].second] = j;
      } else {
        if (mp.count(vp[j].first)) {
          br = 1;
          break;
        }
        mp[vp[j].first] = j;
      }
    }
    if (!br)
      (ans += 1) %= mod;
    if (!br)
      st.insert(mp);
  }
  ans = st.size();
  // dbg(st);
  cout << ans;
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
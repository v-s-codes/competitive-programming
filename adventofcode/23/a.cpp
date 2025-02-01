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
  map<string, set<string>> mp;
  set<string> s;
  string ss;
  while (cin >> ss) {
    auto a = ss.substr(0, 2);
    auto b = ss.substr(3, 2);
    mp[a].insert(b);
    mp[b].insert(a);
    s.insert(a);
    s.insert(b);
  }
  dbg(s.size());
  int ans = 0;
  for (auto x : s) {
    for (auto y : mp[x]) {
      for (auto z : mp[y]) {
        if ((x[0] == 't' || y[0] == 't' || z[0] == 't') && z != x &&
            mp[x].find(z) != mp[x].end()) {
          ans++;
        }
      }
    }
  }

  cout << ans / 6;
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
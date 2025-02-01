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
  string ans = "";
  int mx = 0;
  int iii = 0;
  for (auto z : s) {
    vector<string> vv;
    vv.push_back(z);
    for (auto zz : mp[z]) {
      vv.push_back(zz);
    }
    int n = vv.size();
    set<string> x;
    for (int i = 1; i < (1 << n); i++) {
      bool found = true;
      for (int j = 0; j < n; j++) {
        if (i & (1 << j))
          x.insert(vv[j]);
      }
      for (auto a : x) {
        for (auto b : x) {
          if (a == b)
            continue;
          if (mp[a].find(b) == mp[a].end()) {
            found = false;
            break;
          }
        }
        if (!found)
          break;
      }
      if (found && x.size() > mx) {
        mx = x.size();
        ans = "";
        for (auto xx : x) {
          ans += xx;
          ans += ",";
        }
        ans.pop_back();
      }
    }
    dbg(iii++, n);
  }

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
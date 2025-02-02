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
  string s;
  cin >> s;
  int n = s.size();
  map<char, int> mp;
  mp['1'] = 2;
  mp['2'] = 3;
  mp['3'] = 5;
  mp['4'] = 7;
  mp['5'] = 7;
  mp['6'] = 11;
  mp['7'] = 11;
  mp['8'] = 11;
  mp['9'] = 11;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      cout << mp[s[i]];
    } else {
      cout << 0;
    }
  }
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
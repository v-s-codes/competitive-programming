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
  string s;
  cin >> s;
  if (n % 2 == 0) {
    map<char, int> odd, even;
    for (i = 0; i < n; i++) {
      if (i & 1) {
        odd[s[i]]++;
      } else {
        even[s[i]]++;
      }
    }
    char mxo = 'a', mxe = 'a';
    for (auto z : odd) {
      if (z.second > odd[mxo])
        mxo = z.first;
    }
    for (auto z : even) {
      if (z.second > even[mxe])
        mxe = z.first;
    }
    dbg(mxo, mxe);
    int cnt = (n / 2);
    int ans = (cnt - odd[mxo]) + (cnt - even[mxe]);
    cout << ans;
    return;
  }
  vector<vector<pair<int, int>>> vp(26, vector<pair<int, int>>(n + 1, {0, 0}));
  for (int i = 1; i <= n; i++) {
    int x = (s[i - 1] - 'a');
    for (int j = 0; j < 26; j++) {
      if (j == x) {
        if (i & 1) {
          // 1 based odd
          vp[j][i] = {vp[j][i - 1].first, vp[j][i - 1].second + 1};
        } else {
          vp[j][i] = {vp[j][i - 1].first + 1, vp[j][i - 1].second};
        }
      } else {
        vp[j][i] = vp[j][i - 1];
      }
    }
  }
  int ans = LLONG_MAX;
  for (int i = 0; i < n; i++) {
    vector<int> odd(26, 0), even(26, 0);
    for (int j = 0; j < 26; j++) {
      odd[j] = vp[j][i].first + (vp[j][n].second - vp[j][i + 1].second);

      even[j] = vp[j][i].second + (vp[j][n].first - vp[j][i + 1].first);
    }
    int mxo = 0, mxe = 0;
    for (int i = 0; i < 26; i++) {
      if (odd[i] > odd[mxo]) {
        mxo = i;
      }
      if (even[i] > even[mxe]) {
        mxe = i;
      }
    }
    int cnt = (n / 2);
    ans = min(ans, 1 + (cnt - odd[mxo]) + (cnt - even[mxe]));
  }
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
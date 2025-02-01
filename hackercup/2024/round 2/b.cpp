#include "bits/stdc++.h"
#include <algorithm>
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
  int n = 6, m = 7;
  vector<string> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  vector<int> p({0, 1, 2, 3, 4, 5, 6});
  vector<int> ans({0, 0});
  string ss = "CF";
  do {
    vector<string> s(n, string(m, '.'));
    bool valid = true;
    for (auto j : p) {
      int cnt = 0;
      for (int i = n - 1; i >= 0; i--) {
        auto c = ss[cnt];
        if (v[i][j] != c) {
          valid = false;
          break;
        }
        s[i][j] = c;
        if (i + 3 < n && s[i + 3][j] == c && s[i + 2][j] == c &&
            s[i + 1][j] == c) {
          ans[cnt]++;
          valid = false;
          break;
        }
        if (i - 3 >= 0 && s[i - 3][j] == c && s[i - 2][j] == c &&
            s[i - 1][j] == c) {
          ans[cnt]++;
          valid = false;
          break;
        }
        if (j + 3 < m && s[i][j + 3] == c && s[i][j + 2] == c &&
            s[i][j + 1] == c) {
          ans[cnt]++;
          valid = false;
          break;
        }
        if (j - 3 >= 0 && s[i][j - 3] == c && s[i][j - 2] == c &&
            s[i][j - 1] == c) {
          ans[cnt]++;
          valid = false;
          break;
        }
        if (i + 3 < n && j + 3 < m && s[i + 3][j + 3] == c &&
            s[i + 2][j + 2] == c && s[i + 1][j + 1] == c) {
          ans[cnt]++;
          valid = false;
          break;
        }
        if (i + 3 < n && j - 3 >= 0 && s[i + 3][j - 3] == c &&
            s[i + 2][j - 2] == c && s[i + 1][j - 1] == c) {
          ans[cnt]++;
          valid = false;
          break;
        }
        if (i - 3 >= 0 && j - 3 >= 0 && s[i - 3][j - 3] == c &&
            s[i - 2][j - 2] == c && s[i - 1][j - 1] == c) {
          ans[cnt]++;
          valid = false;
          break;
        }
        if (i - 3 >= 0 && j + 3 < m && s[i - 3][j + 3] == c &&
            s[i - 2][j + 2] == c && s[i - 1][j + 1] == c) {
          ans[cnt]++;
          valid = false;
          break;
        }
        cnt = 1 - cnt;
      }
      if (!valid)
        break;
    }
  } while (next_permutation(p.begin(), p.end()));
  cout << ans[0] << " " << ans[1];
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
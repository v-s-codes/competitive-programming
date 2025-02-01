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
int isPerfectSquare(long double x) {
  if (x >= 0) {
    int sr = sqrt(x);
    if (sr * sr == x)
      return sr;
    return -1;
  }
  return -1;
}
void solve() {
  int n;
  string s;
  cin >> n >> s;
  int sr = isPerfectSquare(n);
  if (sr == -1) {
    cout << "No";
    return;
  }
  for (int i = 0; i < sr; i++) {
    for (int j = 0; j < sr; j++) {
      char c = s[(i * sr + j)];
      if (i == 0 || i == sr - 1 || j == 0 || j == sr - 1) {
        if (c == '0') {
          cout << "No";
          return;
        }
      } else {
        if (c == '1') {
          cout << "No";
          return;
        }
      }
    }
  }
  cout << "Yes";
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
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
  int n, i, c, d;
  cin >> n >> c >> d;
  int m = n * n;
  vector<int> v(m);
  int mn = LLONG_MAX;
  for (i = 0; i < m; i++) {
    cin >> v[i];
    mn = min(mn, v[i]);
  }
  vector<int> us;
  vector<vector<int>> vv(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      vv[i][0] = mn;
    } else {
      vv[i][0] = vv[i - 1][0] + c;
    }
    for (int j = 1; j < n; j++) {
      vv[i][j] = vv[i][j - 1] + d;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      us.push_back(vv[i][j]);
  }
  sort(us.begin(), us.end());
  sort(v.begin(), v.end());
  if (v == us) {
    cout << "YES";
  } else
    cout << "NO";
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
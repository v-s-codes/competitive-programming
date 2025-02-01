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
struct tower {
  int x, y, p;
  map<int, int> m;
};
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<int, int>> vp;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (s[j] == '#')
        vp.push_back({i, j});
    }
  }
  vector<tower> tw(k);
  for (int i = 0; i < k; i++)
    cin >> tw[k].x >> tw[k].y >> tw[k].p;

  for (auto z : tw) {
    for (auto zz : vp) {
      int d = ceil(sqrtl((z.x - zz.first) * (z.x - zz.first) +
                         (z.y - zz.second) * (z.y - zz.second)));
      z.m[d]++;
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
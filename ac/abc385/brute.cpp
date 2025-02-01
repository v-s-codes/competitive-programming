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

// void dbgg(map<int, map<int, int>> x){
//   dbg("x");
//   for(auto z:x){
//     dbg(z.first, z.second);
//   }
// }
void solve() {
  int n, m, sx, sy;
  cin >> n >> m >> sx >> sy;
  vector<pair<int, int>> xy(n);
  vector<pair<char, int>> dc(m);
  for (int i = 0; i < n; i++)
    cin >> xy[i].first >> xy[i].second;
  for (int i = 0; i < m; i++)
    cin >> dc[i].first >> dc[i].second;

  set<pair<int, int>> s;
  s.insert({sx, sy});
  for (auto z : dc) {
    if (z.first == 'L' || z.first == 'R') {
      int delta = ((z.first == 'L') ? (-1 * z.second) : z.second);
      int new_x = sx + delta;
      int mn = min(sx, new_x), mx = max(sx, new_x);
      for (int i = mn; i <= mx; i++) {
        s.insert({i, sy});
      }
      sx = new_x;
    } else {
      int delta = ((z.first == 'D') ? (-1 * z.second) : z.second);
      int new_y = sy + delta;
      int mn = min(sy, new_y), mx = max(sy, new_y);
      for (int i = mn; i <= mx; i++) {
        s.insert({sx, i});
      }
      sy = new_y;
    }
  }
  int ans = 0;
  for (auto z : xy) {
    if (s.find(z) != s.end())
      ans++;
  }
  cout << sx << " " << sy << " " << ans;
  //   dbg("SEX");
}

signed main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  // #ifdef LOCAL
  //   freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", stdout);
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
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

void dbgg(map<int, map<int, int>> x) {
  dbg("x");
  for (auto z : x) {
    dbg(z.first, z.second);
  }
}
void solve() {
  int n, m, sx, sy;
  cin >> n >> m >> sx >> sy;
  vector<pair<int, int>> xy(n);
  vector<pair<char, int>> dc(m);
  for (int i = 0; i < n; i++)
    cin >> xy[i].first >> xy[i].second;
  for (int i = 0; i < m; i++)
    cin >> dc[i].first >> dc[i].second;
  map<int, map<int, int>> x, y, pre_x, pre_y;

  for (auto z : dc) {
    if (z.first == 'L' || z.first == 'R') {
      int delta = ((z.first == 'L') ? (-1 * z.second) : z.second);
      int new_x = sx + delta;
      int mn = min(sx, new_x), mx = max(sx, new_x);
      x[sy][mn]++;
      x[sy][mx + 1]--;
      sx = new_x;
    } else {
      int delta = ((z.first == 'D') ? (-1 * z.second) : z.second);
      int new_y = sy + delta;
      int mn = min(sy, new_y), mx = max(sy, new_y);
      y[sx][mn]++;
      y[sx][mx + 1]--;
      sy = new_y;
    }
  }
  for (auto z : x) {
    int sum = 0;
    for (auto zz : z.second) {
      sum += zz.second;
      pre_x[z.first][zz.first] = sum;
    }
  }
  for (auto z : y) {
    int sum = 0;
    for (auto zz : z.second) {
      sum += zz.second;
      pre_y[z.first][zz.first] = sum;
    }
  }
  // dbgg(x); dbgg(y); dbgg(pre_x); dbgg(pre_y);
  int total_visited_xy = 0;
  for (auto z : xy) {
    // check in pre_x
    auto up = pre_x[z.second].upper_bound(z.first);
    if (up != pre_x[z.second].end() && up != pre_x[z.second].begin()) {
      up--;
      if (up->second > 0) {
        total_visited_xy++;
        continue;
      }
    }
    // check in pre_y
    up = pre_y[z.first].upper_bound(z.second);
    if (up != pre_y[z.first].end() && up != pre_y[z.first].begin()) {
      up--;
      if (up->second > 0) {
        total_visited_xy++;
        continue;
      }
    }
  }
  cout << sx << " " << sy << " " << total_visited_xy;
  dbg("SEX");
}

signed main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("my_output.txt", "w", stdout);
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
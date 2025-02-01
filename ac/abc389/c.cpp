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
  deque<pair<int, int>> dq;
  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    if (x == 1) {
      int y;
      cin >> y;
      if (dq.empty()) {
        dq.push_back({0, y - 1});
      } else {
        dq.push_back({dq.back().second + 1, dq.back().second + y});
      }
    } else if (x == 2) {
      dq.pop_front();
    } else {
      int k;
      cin >> k;
      dbg(k, dq.size());
      cout << dq[k - 1].first - dq.front().first << "\n";
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
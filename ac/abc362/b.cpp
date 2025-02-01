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
struct point {
  int x;
  int y;
};
point arr[3];
int dist(int i, int j) {
  return (arr[i].x - arr[j].x) * (arr[i].x - arr[j].x) +
         (arr[i].y - arr[j].y) * (arr[i].y - arr[j].y);
}
void solve() {
  cin >> arr[0].x >> arr[0].y;
  cin >> arr[1].x >> arr[1].y;
  cin >> arr[2].x >> arr[2].y;
  for (int i = 0; i < 3; i++) {
    int j = 0;
    if (j == i)
      j++;
    int k = 3 - (i + j);
    if (dist(i, j) + dist(i, k) == dist(j, k)) {
      cout << "Yes";
      return;
    }
  }
  cout << "No";
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
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
int mn(int x) {
  if (x < 2) {
    return 0;
  }
  // x-2-> (x-2)/2, (x-1)/2
  int rem = x - 2;
  int left = rem / 2, right = rem - left;
  if (left % 2 == 0 && right % 2 == 0 && max(left, right) > 0) {
    if (left > right) {
      left--;
      right++;
    } else {
      left++;
      right--;
    }
  }
  return 1 + mn(left) + mn(right);
}
void solve() {
  int n, i;
  cin >> n;
  cout << (n + 1) / 3 << " " << n / 2;
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
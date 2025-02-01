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
vector<int> v;
int n;
void solve() {
  cin >> n;
  v.clear();
  v.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  // iterate over all integers from 0 to 2^n
  int ans = 0;
  for (int i = 0; i < (1 << n); i++) {
    vector<int> sb;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        sb.push_back(v[j]);
      }
    }
    bool br = false;
    int x = sb.size();
    if (x > 0 && x % 2 == 0) {
      for (int j = 0; j < x / 2; j++) {
        if (sb[j] * 2 > sb[j + x / 2]) {
          br = true;
          break;
        }
      }
      if (!br) {
        ans = max(ans, x / 2);
      }
    }
  }
  cout << ans;

  // dbg("SEX");
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
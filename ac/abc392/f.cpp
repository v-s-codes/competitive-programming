#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set                                                            \
  tree<int, null_type, less<int>, rb_tree_tag,                                 \
       tree_order_statistics_node_update>

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
  int n, i;
  cin >> n;
  ordered_set os;
  vector<int> v(n);
  for (i = 0; i < n; i++) {
    cin >> v[i];
    os.insert(i);
  }
  vector<int> ans(n);
  for (i = n - 1; i >= 0; i--) {
    int x = v[i] - 1;
    int y = *(os.find_by_order(x));
    ans[y] = i + 1;
    os.erase(y);
  }
  for (auto z : ans)
    cout << z << " ";
  dbg("SEX");
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
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
  int n, i, m, q;
  cin >> n >> m >> q;
  vector<int> v(m);
  for (i = 0; i < m; i++) {
    cin >> v[i];
  }
  v.push_back(INT_MIN);
  v.push_back(INT_MAX);
  sort(v.begin(), v.end());
  while (q--) {
    int x;
    cin >> x;
    auto low = lower_bound(v.begin(), v.end(), x) - v.begin();
    auto high = upper_bound(v.begin(), v.end(), x) - v.begin();
    if (v[low] == x) {
      cout << 0 << "\n";
      continue;
    }
    low--;
    if (v[low] == INT_MIN) {
      cout << v[high] - 1 << "\n";
    } else if (v[high] == INT_MAX) {
      cout << n - v[low] << "\n";
    } else {

      cout << ((v[high] + v[low]) / 2 - v[low]) << "\n";
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
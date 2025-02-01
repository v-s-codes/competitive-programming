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
  int n, i, m;
  cin >> n >> m;
  vector<int> v(n), u(n);
  for (auto &z : v) {
    cin >> z;
  }
  for (auto &z : u) {
    cin >> z;
  }
  for (int i = 0; i < n; i++) {
    u[i] = min(u[i], v[i]);
  }
  for (int i = n - 2; i >= 0; i--) {
    u[i] += u[i + 1];
  }
  dbg(u);
  int curr = 1e18;
  dbg(curr);
  for (int i = 0; i < m; i++) {
    curr = min(v[i] + ((i == n - 1) ? 0 : u[i + 1]), curr);
    dbg(i, curr);
  }
  cout << curr;
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
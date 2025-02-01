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
  int n, i, k;
  cin >> n >> k;
  vector<vector<int>> v(n, vector<int>(n, 0)), u(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      cin >> v[i][j];
    }
  }
  dbg(v);
  int tot = 1;
  priority_queue<int> pq;
  pq.push(0);
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i; j < n; j++) {
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
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
  int n, i;
  cin >> n;
  vector<int> v(n);
  int sm = 0;
  for (i = 0; i < n; i++) {
    cin >> v[i];
    sm += v[i];
  }
  sort(v.begin(), v.end());
  if (n <= 2) {
    cout << -1;
    return;
  }
  int lo = 0, hi = 1e15, mid;
  while (lo < hi) {
    mid = (lo + hi) / 2;
    int sm1 = sm + mid;
    if (v[n / 2] * 2 * n < sm1)
      hi = mid;
    else
      lo = mid + 1;
  }
  cout << lo;
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
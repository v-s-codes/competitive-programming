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
  vector<int> a(n);
  vector<int> b(n);
  set<int> vals;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    vals.insert(a[i]);
  }
  sort(a.begin(), a.end());
  for (i = 0; i < n; i++) {
    cin >> b[i];
    vals.insert(b[i]);
  }
  sort(b.begin(), b.end());
  int mx = 0;
  for (auto x : vals) {
    int cnta = lower_bound(a.begin(), a.end(), x) - a.begin();
    cnta = n - cnta;
    int cntb = lower_bound(b.begin(), b.end(), x) - b.begin();
    cntb = n - cntb;
    if ((cntb - cnta) > k)
      continue;
    dbg(x, cnta, cntb);
    mx = max(mx, cntb * x);
  }
  cout << mx;
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
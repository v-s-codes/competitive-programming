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
  int n, i, m, k;
  cin >> n >> m >> k;
  vector<int> v(n);
  for (i = 0; i < n; i++) {
    cin >> v[i];
  }
  vector<int> pre({0});
  sort(v.begin(), v.end());
  for (auto z : v) {
    pre.push_back(pre.back() + z);
  }
  int mn = (k + m - 1) / m;
  long long ans = LLONG_MAX;
  for (i = mn; i <= min(k, n); i++) {
    int rem = k - i;
    int l;
    if (m == 1) {
      l = i;
    } else
      l = (rem / (m - 1));
    // dbg(l, i);
    if (l == i) {
      ans = min(ans, pre[i] * m + (k * k - m * m * i) / 2);
      // dbg(ans);
    } else if (i == l + 1) {
      int price = pre[i - 1] * m + (k - m * l) * v[i - 1];
      price += (k * k - m * m * l - (k - m * l) * (k - m * l)) / 2;
      ans = min(ans, price);
      // dbg(ans);
    } else {
      int a = l;
      int b = 1;
      int c = i - l - 1;
      int p = m, r = 1, q = k - p * a - c * r;
      // dbg(a, b, c);
      // dbg(p,q  ,r);
      int tot = pre[a] * p + (pre[a + b] - pre[a]) * q + (pre[i] - pre[b]) * r;
      tot += (k * k - p * p * a - q * q * b - r * r * c) / 2;
      ans = min(ans, tot);
      // dbg(ans);
    }
  }
  cout << ans;
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
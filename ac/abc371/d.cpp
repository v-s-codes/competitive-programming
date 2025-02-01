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

void solve() {
  int n;
  cin >> n;
  vector<int> x(n), p(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    mp[x[i]] += p[i];
  }
  vector<pair<int, int>> v;
  for (auto i : mp) {
    v.push_back({i.first, i.second});
  }
  sort(v.begin(), v.end());
  x.clear();
  p.clear();
  for (auto i : v) {
    x.push_back(i.first);
    p.push_back(i.second);
  }
  vector<int> pre({0});
  for (int i = 0; i < n; i++) {
    pre.push_back(pre.back() + p[i]);
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    auto lb = lower_bound(x.begin(), x.end(), l);
    auto ub = upper_bound(x.begin(), x.end(), r);
    int ans = 0;
    if (lb == ub) {
      cout << 0 << "\n";
      continue;
    }
    int lbidx = lb - x.begin();
    int ubidx = ub - x.begin();
    ans = pre[ubidx] - pre[lbidx];
    cout << ans << "\n";
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
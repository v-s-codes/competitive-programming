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
  vector<int> v(n), cnt(n + 1, 0);
  map<int, int> mp;
  int mcnt = 0;
  for (i = 0; i < n; i++) {
    cin >> v[i];
    mp[v[i]]++;
    mcnt = max(mcnt, mp[v[i]]);
  }
  int ans = 1;
  for (auto x : mp) {
    cnt[x.second]++;
  }
  dbg(cnt, mcnt);
  for (int i = 1; i <= n; i++) {
    if (i == mcnt) {
      cnt[i]--;
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    while (k >= i && cnt[i] > 0) {
      cnt[i]--;
      k -= i;
    }
    ans += cnt[i];
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
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
  vector<pair<int, int>> vp(n);
  for (auto &z : vp)
    cin >> z.first >> z.second;
  reverse(vp.begin(), vp.end());
  vector<int> ans;
  map<int, int> cnt;
  for (auto z : vp) {
    if (z.first == 2)
      cnt[z.second]++;
    else {
      if (cnt.count(z.second)) {
        ans.push_back(1);
        cnt[z.second]--;
        if (cnt[z.second] == 0)
          cnt.erase(z.second);
      } else {
        ans.push_back(0);
      }
    }
  }
  if (!cnt.empty()) {
    cout << -1;
    return;
  }
  reverse(ans.begin(), ans.end());
  reverse(vp.begin(), vp.end());
  int fin = 0, lst = 0;
  int curr = 0;
  for (int i = 0; i < n; i++) {
    if (vp[i].first == 1) {
      if (ans[curr] == 1)
        fin++;
      curr++;
      lst = max(lst, fin);
    } else
      fin--;
  }
  cout << lst << "\n";
  for (auto z : ans)
    cout << z << " ";
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
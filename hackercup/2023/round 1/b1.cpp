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

#define googleOrFacebook
#define testcases

void solve() {
  int n;
  cin >> n;
  vector<int> v;
  int p = 2;
  int tot = 0;
  while (p * p <= n) {
    while (n % p == 0) {
      v.push_back(p);
      tot += p;
      n /= p;
    }
    p++;
  }
  if (n != 1)
    v.push_back(n), tot += n;
  if (tot > 41) {
    cout << -1;
    return;
  }
  while (tot < 41)
    v.push_back(1), tot++;
  sort(v.begin(), v.end());
  n = v.size();
  cout << n << " ";
  for (auto z : v)
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
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
vector<int> v;
int n;
void solve() {
  cin >> n;
  v.clear();
  v.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int lo = 0, hi = n / 2, mid;
  while (lo < hi) {
    mid = (lo + hi + 1) / 2;
    int i = 0, j = n - mid;
    int ot = mid, ff = 0;
    while (i < n && j < n && ot--) {
      if (v[i] * 2 > v[j]) {
        ff = 1;
        break;
      }
      i++;
      j++;
    }
    if (!ff) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  cout << lo;
  // dbg("SEX");
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
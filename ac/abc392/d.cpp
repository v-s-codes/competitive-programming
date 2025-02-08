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
  int n, i;
  cin >> n;
  vector<map<int, int>> mp(n);
  vector<int> v(n);
  for (i = 0; i < n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int x;
      cin >> x;
      mp[i][x]++;
    }
    v[i] = k;
  }
  long double total = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      long double lena = v[i], lenb = v[j];
      auto mpa = mp[i], mpb = mp[j];
      if (lena > lenb) {
        swap(lena, lenb);
        swap(mpa, mpb);
      }
      long double ans = 0;
      for (auto z : mpa) {
        if (mpb.count(z.first)) {
          ans += (z.second / lena) * (mpb[z.first] / lenb);
        }
      }
      total = max(ans, total);
    }
  }
  // cout << fixed << setprecision(10)
  cout << total;
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
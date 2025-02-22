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
  vector<int> owner_of_bib(n), victim(n), bib(n);
  for (i = 0; i < n; i++) {
    int x;
    cin >> x;
    victim[i] = x - 1;
  }
  for (i = 0; i < n; i++) {
    int x;
    cin >> x;
    bib[i] = x - 1;
    owner_of_bib[x - 1] = i;
  }
  for (int i = 0; i < n; i++) {
    auto al = owner_of_bib[i];
    auto be = victim[al];
    auto ga = bib[be];
    cout << ga + 1 << " ";
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
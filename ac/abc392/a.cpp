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
  n = 3;
  vector<int> v(n);
  map<int, set<int>> s;
  int total = 0;
  for (i = 0; i < n; i++) {
    cin >> v[i];
    s[v[i]].insert(i);
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int k = v[i] * v[j];
      for (auto al : s[k]) {
        dbg(i, j, al);
        if (al != i && al != j) {
          cout << "Yes";
          return;
        }
      }
    }
  }
  cout << "No";
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
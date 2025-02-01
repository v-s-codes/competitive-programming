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
  int n, i;
  cin >> n;
  vector<set<int>> v(n), rev(51);
  i = 0;
  map<int, int> al;
  for (auto &z : v) {
    int k;
    cin >> k;
    while (k--) {
      int x;
      cin >> x;
      z.insert(x);
      al[x]++;
      rev[x].insert(i);
    }
    i++;
  }
  int ans = 0;
  for (int i = 1; i <= 50; i++) {
    if (rev[i].empty())
      continue;
    auto cpy = al;
    for (auto z : rev[i]) {
      for (auto zz : v[z]) {
        if (cpy.count(zz)) {
          cpy[zz]--;
          if (cpy[zz] == 0)
            cpy.erase(zz);
        }
      }
    }
    dbg(i, cpy);
    ans = max((int)ans, (int)(cpy.size()));
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
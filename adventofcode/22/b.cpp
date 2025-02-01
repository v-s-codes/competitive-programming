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

const int mod = 16777216;

// #define googleOrFacebook
// #define testcases

void solve() {
  vector<int> v;
  int x;
  while (cin >> x)
    v.push_back(x);
  // {1st, 2nd, 3rd, 4th}
  int mp[19][19][19][19];
  memset(mp, 0, sizeof(mp));
  int dn = 0;
  for (auto z : v) {
    vector<int> delta;
    set<vector<int>> sv;
    int sz = 0;
    auto cpy = z;
    for (int i = 0; i < 2000; i++) {
      auto m64 = z * 64;
      z = (m64 ^ z);
      z %= mod;
      auto d32 = z / 32;
      z = (z ^ d32);
      z %= mod;
      auto m2048 = z * 2048;
      z = (m2048 ^ z);
      z %= mod;
      delta.push_back(z % 10 - cpy % 10);
      cpy = z;
      sz++;
      if (sz >= 4) {
        vector<int> temp;
        temp.push_back(delta[sz - 4]);
        temp.push_back(delta[sz - 3]);
        temp.push_back(delta[sz - 2]);
        temp.push_back(delta[sz - 1]);
        if (sv.find(temp) == sv.end()) {
          sv.insert(temp);
          mp[temp[0] + 9][temp[1] + 9][temp[2] + 9][temp[3] + 9] += (z % 10);
        }
      }
    }
    dn++;
    dbg(dn);
  }
  int ans = 0;
  for (int i = 0; i < 19; i++) {
    for (int j = 0; j < 19; j++) {
      for (int k = 0; k < 19; k++) {
        for (int l = 0; l < 19; l++) {
          ans = max(ans, mp[i][j][k][l]);
        }
      }
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
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

const int mod = 998244353;

// #define googleOrFacebook
// #define testcases
int n;
vector<int> v, d;
// first term, second term, current index, remaining
vector<vector<vector<vector<int>>>> dp;

int fun(int d, int j, int k, int l) {}
void solve() {
  int i;
  cin >> n;
  v.clear();
  v.resize(n);
  for (i = 0; i < n; i++) {
    cin >> v[i];
  }
  d.clear();
  set<int> s;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < n; j++) {
    }
  }
  dp.clear();
  dp.resize(n + 1,
            vector<vector<vector<int>>>(
                n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1))));
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
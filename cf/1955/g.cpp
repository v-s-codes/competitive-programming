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

vector<vector<int>> divi;
void div(int n) {
  divi.clear();
  divi.resize(n);
  for (int i = 1; i <= n; i++)
    divi[i].push_back(1);
  for (int i = 2; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      divi[j].push_back(i);
    }
  }
}
vector<vector<int>> v, dp;
int n, m, k;
int fun(int i, int j) {
  if (i == n - 1 && j == m - 1)
    return 1;
  if (dp[i][j] != -1)
    return dp[i][j];
  if (v[i][j] % k)
    return dp[i][j] = 0;
  if ((i < n - 1 && dp[i + 1][j]) || (j < m - 1 && dp[i][j + 1]))
    return dp[i][j] = 1;
}
void solve() {

  cin >> n >> m;
  v.clear();
  v.resize(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cin >> v[i][j];
  }
  int g = __gcd(v[0][0], v[n - 1][m - 1]);
  int x = divi[g].size();
  for (int i = x - 1; i >= 0; i--) {
    k = divi[g][i];

    dp.clear();
    dp.resize(n, vector<int>(m, -1));
    if (fun(0, 0)) {
      cout << k;
      return;
    }
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
  div(1000001);
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
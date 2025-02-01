#include "bits/stdc++.h"
using namespace std;
#define int long long

#ifdef LOCAL
#include "lib/debug.h"
#define dbg(...) \
  cerr << "Line " << __LINE__ << ": " FOR_EACH_MACRO(out, __VA_ARGS__) << "\n"
#else
#define dbg(...) 69
#endif

const int mod = 998244353;
int power(int x, int y)
{
  int res = 1;
  x = x % mod;
  if (x == 0)
    return 0;
  while (y > 0)
  {
    if (y & 1)
      res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}
// #define googleOrFacebook
// #define testcases
// a(n) = 3*a(n-1) - a(n-2)
vector<int> dp;
int fun(int sz)
{
  // dbg(sz);
  // return 0;
  if (sz < 0)
    return 0;
  if (sz == 0)
    return 0;
  if (sz == 1)
    return 1;
  if (sz == 2)
    return 3;
  if (dp[sz] != -1)
    return dp[sz];
  return dp[sz] = (3 * fun(sz - 1) - fun(sz - 2) + mod) % mod;
}

void solve()
{
  int n, i, m;

  cin >> n >> m;

  vector<int> v({0});
  for (i = 0; i < m; i++)
  {
    int x;
    cin >> x;
    v.push_back(x);
  }
  dp.clear();
  dp.resize(n + 1, -1);
  sort(v.begin(), v.end());
  v.push_back(n + 1);
  // dbg(v);
  int ans = 1;
  for (i = 1; i < v.size(); i++)
  {
    // dbg(v[i]-v[i-1]-1);
    (ans *= fun(v[i] - v[i - 1] - 1)) %= mod;
  }
  cout << ans;
  // dbg(dp);
  dbg("SEX");
}

signed main()
{
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
  while (t <= tt)
  {
#ifdef googleOrFacebook
    cout << "Case #" << t << ": ";
#endif
    solve();
    cout << "\n";
    t++;
  }
  return 0;
}
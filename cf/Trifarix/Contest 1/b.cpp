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

const int mod = 1e9 + 7;

// #define googleOrFacebook
// #define testcases
int n; 
vector<int> v, dp;
int fun(int i){
  if(i>=n)return 0;
  if(dp[i]!=-1)return dp[i];
  dp[i]=n-i;
  for(int j=i;j<=min(n-1, i+100);j++){
    if(i>=j-v[j])dp[i]=min(fun(j+v[j]+1)+1, dp[i]);
  }
  return dp[i];
}
void solve()
{
    int i;
    cin >> n;
    v.clear(); v.resize(n);
    for (auto &z : v)
    {
        cin >> z;
    }
    dp.clear(); dp.resize(n, -1);
    cout<<fun(0);
    dbg(dp);
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
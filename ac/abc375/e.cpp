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
vector<pair<int, int>> v;
int w;
int dp[101][501][501];
int fun(int i, int a, int b){
  if(a>500 || b>500){
    return 1e9;
  }
  if(i==n){
    if(a==b && a==w){
      return 0;
    }
    return 1e9;
  }
  if(dp[i][a][b]!=-1){
    return dp[i][a][b];
  }
  int ans=1e9;
    ans=min(ans, (int)(v[i].first!=1)+fun(i+1, a+v[i].second, b));
    ans=min(ans, (int)(v[i].first!=2)+fun(i+1, a, b+v[i].second));
    ans=min(ans, (int)(v[i].first!=3)+fun(i+1, a, b));
  return dp[i][a][b]=ans;
}
void solve()
{
  
  cin >> n;
  v.clear(); v.resize(n);
  w=0;
  for (int i = 0; i < n; i++)
  {
    cin >> v[i].first >> v[i].second;
    w+=v[i].second;
  }
  if(w%3){
    cout<<-1; return;
  }
  w/=3;
  memset(dp, -1, sizeof dp);
  int ans=fun(0, 0, 0);
  if(ans>=1e9){
    cout<<-1; return;
  }
  cout<<ans;
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
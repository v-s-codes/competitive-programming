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
vector<vector<int>> diff;
int n;
vector<int> dp[21];
vector<int> mx;
int solve(int mask, int last)
{
  if(mask==((1<<n)-1))return mx[last];
  if(dp[last][mask]!=-1)return dp[last][mask];
  int ans=1e9;
  for(int i=0;i<n;i++){
    if(mask&(1<<i))continue;
    ans=min(ans, 1+diff[last][i]+solve((mask|(1<<i)),i));
  }
  return dp[last][mask]=ans;
}
void solve()
{
  int i,q;
  cin >> n>>q;
  vector<int> v(q);
  mx.clear(); mx.resize(n,1);
  diff.clear(); diff.resize(n,vector<int>(n,0));
  vector<vector<pair<int,int>>> vp(q,vector<pair<int,int>>(n,{0,0}));
  for (i = 0; i < q; i++)
  {
    int x; char c;
    cin >> x>>c; x--;
    if(i>0){
      vp[i]=vp[i-1];
    }
    if(c=='+')vp[i][x].second++;
    else vp[i][x].first++;
    mx[x]=max(mx[x], vp[i][x].second+1);
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i==j)continue;
      int cnt=0;
      for(int k=0;k<q;k++){
        cnt=min(cnt, vp[k][j].first-vp[k][i].second);
      }
      diff[i][j]=-1*cnt;
    }
  }
  dbg(diff);
  for(int i=0;i<n;i++){
    dp[i].clear();
    dp[i].resize(1<<n,-1);
  }
  int ans=1e9;
  for(int i=0;i<n;i++){
    ans=min(ans, solve((1<<i),i));
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
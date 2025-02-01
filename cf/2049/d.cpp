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
#define testcases
int n, m, k;
vector<vector<int>> v;
vector<vector<vector<int>>> dp;
int fun(int i, int j, int move){
  int actual_j=(j+move)%m;
  if(i<0 || j<0 || i>=n || j>=m || move>=m){
    return 1e14;
  }
  if(i==n-1 && j==m-1){
    return v[i][actual_j];
  }
  if(dp[i][j][move]!=-1){
    return dp[i][j][move];
  }
  int ans=v[i][actual_j]+fun(i, j+1, move);

  for(int new_move=0;new_move<m;new_move++){
    ans=min(ans, v[i][actual_j]+k*new_move+fun(i+1, j, new_move));
  }
  // if(i==1 && j==1 && move==1){
  //   dbg(i, j, move, ans);
  // }
  return dp[i][j][move]=ans;
}
void solve()
{
  cin>>n>>m>>k;
  v.clear(); v.resize(n, vector<int>(m));
  for(auto &z:v){
    for(auto &x:z){
      cin>>x;
    }
  }
  dp.clear(); dp.resize(n, vector<vector<int>>(m, vector<int>(m, -1)));
  int ans=1e14;
  for(int i=0;i<m;i++){
    ans=min(ans, k*i+fun(0, 0, i));
  }
  cout<<ans;
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
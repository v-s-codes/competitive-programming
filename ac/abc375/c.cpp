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
pair<int,int> fun(int cnt, pair<int,int> p, int n){
  cnt%=4;
  if(cnt==0){
    return p;
  }
  if(cnt==1){
    return {p.second, n-1-p.first};
  }
  return fun(cnt-1,{p.second, n-1-p.first},n);
}
void solve()
{
  int n, i;
  cin >> n;
  vector<string> v(n);
  for (i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  vector<string> ans(n, string(n, '.'));
  dbg(ans);
  for(int i=0;i<n/2;i++){
    int cnt=(i+1);
    for(int x=i;x<=n-i-1;x++){
      int y=i;
        pair<int,int> p=fun(cnt,{x,y},n);
        dbg(x, y, cnt, n, p);
        ans[p.first][p.second]=v[x][y];
        y=n-i-1;
        p=fun(cnt,{x,y},n);
        ans[p.first][p.second]=v[x][y];
    }
    for(int y=i;y<=n-i-1;y++){
      int x=i;
        pair<int,int> p=fun(cnt,{x,y},n);
        ans[p.first][p.second]=v[x][y];
        x=n-i-1;
        p=fun(cnt,{x,y},n);
        ans[p.first][p.second]=v[x][y];
    }
  }
  for(int i=0;i<n;i++){
    cout<<ans[i]<<"\n";
  }
  dbg(ans);
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
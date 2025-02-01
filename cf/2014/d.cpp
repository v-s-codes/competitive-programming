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
int n, d, k;
vector<int> v,u,preU,preV;
void solve()
{
  cin>>n>>d>>k;
  v.clear(); u.clear();
  v.resize(n+1,0); u.resize(n,0);
  for(int i=0;i<k;i++)
  {
    int x, y; cin>>x>>y;
    x--; y--;
    v[x]++;
    u[x]++;
    v[y+1]--;  
  }
  preU.clear(); preU.push_back(0);
  for(int i=0;i<n;i++)
  {
    preU.push_back(preU.back()+u[i]);
  }
  preV.clear(); preV.push_back(0);
  for(int i=0;i<n;i++)
  {
    preV.push_back(preV.back()+v[i]);
  }
  int mn=1e18, mn_i=-1, mx_i=-1, mx=-1e18;
  for(int i=0;i<n;i++)
  {
    int l=i, r=i+d-1;
    if(r>=n) break;
    int tot=preV[l+1]+preU[r+1]-preU[l+1];
    if(tot>mx)
    {
      mx=tot;
      mx_i=i;
    }
    if(tot<mn)
    {
      mn=tot;
      mn_i=i;
    }
  }
  cout<<mx_i+1<<" "<<mn_i+1;
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
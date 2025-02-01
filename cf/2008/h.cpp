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

void solve()
{
  int n, i, q;
  cin >> n>>q;
  vector<int> v(n);
  for (i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  vector<int> u(q);
  for(auto &z:u)cin>>z;
  vector<int> ans(n+1, 0);
  for(i=2;i<=n;i++){
    int lo=0, hi=i-1, mid;
    while(lo<hi){
      mid=(lo+hi)/2;
      int tot=0;
      for(int j=0;j<=n;j+=i){
        int l=j, r=j+mid;
        auto lb=lower_bound(v.begin(), v.end(), l);
        auto up=upper_bound(v.begin(), v.end(), r);
        // dbg(mid, j, up-lb);
        tot+=(up-lb);
        if(tot>(n/2))break;
      }
      if(tot<=(n/2)){
        lo=mid+1;
      }
      else{hi=mid;}
    }
    ans[i]=lo;
  }
  for(auto z:u)cout<<ans[z]<<" ";
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
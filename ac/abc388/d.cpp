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

void solve()
{
  int n, i;
  cin >> n;
  vector<int> v(n);
  for (i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  map<int,int> mp;
  int cnt=0;
  for(int i=0;i<n;i++){
    if(i==2){
      dbg(mp, cnt);
    }
    while(!mp.empty() && i>mp.begin()->first){
      cnt-=mp.begin()->second;
      mp.erase(mp.begin());
    }
    int tot=((n-i-1)-cnt);
    if(tot>=v[i]){
      mp[v[i]+cnt+i]++;
      v[i]=0;
    } else{
      v[i]-=tot;
      mp[n-1]++;
    }
    cnt++; 
  }
  for(int i=0;i<n;i++){
    cout<<v[i]<<" ";
  }
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
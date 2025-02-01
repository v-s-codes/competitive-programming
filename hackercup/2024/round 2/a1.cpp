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

#define googleOrFacebook
#define testcases
vector<int> poss;
void solve()
{
  int a,b,m,ans=0; cin>>a>>b>>m;
  for(auto z:poss){
    if(z>=a && z<=b && z%m==0){
      ans++;
    }
  }
  cout<<ans;
  dbg("SEX");
}

signed main()
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  poss.clear();
  for(int i = 0; i < 9; i++)
  {
    int k=2*i+1;
    for(int j=1;j<10-i;j++){
      int al=j;
      int be=k;
      string s="";
      auto curr=al;
      while(be--){
        s.push_back('0'+curr);
        if(be>i)curr++;
        else curr--;
      }
      poss.push_back(stoll(s));
    }
  }
  dbg(poss);
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
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
const int NUM=1e6;
int hashed(pair<int,int> p){
  return p.first*NUM+p.second;
}
pair<int,int> unhash(int x){
  return {x/NUM, x%NUM};
}
void solve()
{
  int n, w; cin>>n>>w;
  vector<pair<int,int>> vp(n);
  for(int i=0;i<n;i++) cin>>vp[i].first, cin>>vp[i].second;
  unordered_map<int ,int> mp;
  vector<set<int>> m(w+1);
  for(auto z: vp){
    mp[hashed(z)]=LLONG_MAX;
    m[z.first].insert(z.second);
  }
  int al=0;
  while(true){
    if(al++>1000) break;
    int tm=0;
    set<pair<int,int>> s;
    for(int x=1;x<=w;x++){
      auto ys=m[x];
      if(ys.empty()){
        tm=-1;
        break;
      }
      auto it=ys.begin();
      // cout<<*it<<" ";
      tm=max(tm,*it);
      s.insert({x, *it});
      m[x].erase(*it);
    }
    // cout<<endl;
    if(tm==-1) break;
    for(auto z:s){
      mp[hashed(z)]=tm;
    }
  }
  // for(auto z:vp){
  //   cout<<mp[z]<<" ";
  // }
  int q; cin>>q;
  while(q--){
    int t, a; cin>>t>>a;
    if(mp[hashed(vp[a-1])]>t) cout<<"Yes\n";
    else cout<<"No\n";
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
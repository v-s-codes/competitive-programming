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
    int n, i,x,y;
    cin >> n>>x>>y;
    vector<int> v(x);
    for(int i=0;i<x;i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    int two=0;
    map<int,int> me; int mo=0;
    for(int i=1;i<x;i++){
      if(v[i]-v[i-1]==2)two++;
      int d=v[i]-v[i-1];
      if(d<=2)continue;
      if(d%2){
        mo+=d/2;
      }
      else me[d]++;}
      int d=v[0]+n-v[x-1];
    if(d==2)two++;

if(d>2){
         if(d%2){
        mo+=d/2;
      }
      else me[d]++;
}
      for(auto z:me){
        int req=(z.first-4)/2+1;
        int avl=min(z.second, y/req);
        y-=avl*req;
        two+=(req+1)*avl;
        x+=req*avl;
        if(z.second>avl){
          x+=y;
          two+=y; y=0; break;

        }
      }
      two+=min(y, mo);
      x+=min(y, mo);
      cout<<two+max(x-2, 0ll);
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
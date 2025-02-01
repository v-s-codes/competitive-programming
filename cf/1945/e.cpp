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
  int n, i, m;
  cin >> n >> m;
  vector<int> v(n), u;
  for (auto &z : v)
  {
    cin >> z;
  }
  if (n == 1)
  {
    cout << 0;
    return;
  }
  if (n == 2)
  {
    if (v[0] < v[1])
    {
      cout << 0;
      return;
    }
    cout<<"1\n1 2"; return;
  }
  if(n==3){
    vector<pair<int,int>> vp;
    if(v[0]!=1){
      if(v[1]==1){
        vp.push_back({1, 2});
        v[1]=v[0];
        v[0]=1;
      }
      else{
        vp.push_back({1, 3});
        v[2]=v[0];
        v[0]=1;
      }
    }
    if(v[1]!=2){
        vp.push_back({2, 3});
        v[2]=v[1];
        v[1]=2;
    }
    int cnt=vp.size();
    cout<<cnt<<"\n";
    for(auto z:vp)cout<<z.first<<" "<<z.second<<"\n";
    return;
  }
  set<int> s;
  int l=1, r=n+1;
  
  while(l<r){
    int mid=(l+r)/2;
    s.insert(mid);
    u.push_back(mid);
    if(r-l==1)break;
    if(v[mid-1]<=m){
      l=mid;
    }else r=mid;
  }
  if(v[l-1]==m){
    cout<< 0; return;
  }
  int mm=0;
  int nn=0;
  if(v[u.back()-1]<m){
    cout<<1<<"\n";
    for(int i=0;i<n;i++){
      if(v[i]==m){
      mm=i; int al=u.back()-1;
      int temp=v[mm];
      v[mm]=v[al]; v[al]=temp; nn=mm+1;
      mm=al+1;
        cout<<i+1<<" "<<u.back()<<"\n";
        return;
      }
    }
  }
      for(int i=0;i<n;i++){
      if(v[i]==m){
      mm=i;  nn=mm+1;
      }
    }
  if(m==1){
    cout<<1<<"\n";
    cout<<"1 "<<nn; return;
  }
  cout<<2<<"\n";
  cout<<nn<<" "<<u.back()<<"\n";
  u.clear(); s.clear();
    while(l<r){
    int mid=(l+r)/2;
    s.insert(mid);
    u.push_back(mid);
    if(r-l==1)break;
    if(v[mid-1]<=m){
      l=mid;
    }else r=mid;
  }
  cout<<mm<<" "<<u.back()<<"\n";
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
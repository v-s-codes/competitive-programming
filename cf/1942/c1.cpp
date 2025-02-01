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
pair<int,int> fun(int a, int b, int n){
  int x=b-a;
  if(b<a)x+=n;
  dbg(x);
  if(x<=2)return {0, 0};
  return {(x-1)/2, 1-(x&1)};
}
bool comp(pair<int,int> a, pair<int,int> b){
  if(a.second!=b.second){
    return b.second>a.second;
  }
  return b.first<a.first;
}
void solve()
{
  int n, i, x, y;
  cin >> n >> x >> y;
  vector<int> v(x);
  for (int i = 0; i < x; i++)
  {
    cin >> v[i];
  }
sort(v.begin(), v.end());
int tot=0;
int tri=0;
vector<pair<int,int>> vp;
// return;
for(int i=0;i<x;i++){
 vp.push_back(fun(v[i], v[(i+1)%x], n));
 if(i==x-1){
  if((v[0]+n)-v[x-1]==2)tri++;
 }
 else{
  if((v[i+1]-v[i])==2)tri++;
 }
}
// return;
sort(vp.begin(), vp.end(), comp);

dbg(vp);
for(auto z:vp){
  if(y>=z.first){
    y-=z.first;
    tri+=z.first+z.second;
    x+=z.first;
  }
  else{
    tri+=y;
    if(y==z.first)tri+=z.second;
    x+=y;
    y=0;
    break;
  }
}
if(x>=3)tri+=x-2;
cout<<tri;


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
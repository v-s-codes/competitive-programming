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
int fun(vector<int> v, int k){
  dbg(v, k);
  int n=v.size();
  int mx=0;
  for(int i=0;i<k-1;i++){
    mx=max(mx, v[i]);
  }
  if(mx>v[k-1])return 0;
  int ans=1;
  if(k==1){
    ans=0;
  }
  dbg(mx, ans);
  mx=v[k-1];
  for(int i=k;i<n;i++){
    if(mx<v[i])return ans;
    ans++;
  }
  return ans;
}
void solve()
{
  int n, i,k;
  cin >> n>>k;
  vector<int> v(n);
  for (i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  int ans=fun(v, k);
  dbg(ans);
  {
    int l=-1;
    auto cpy =v;
    for(int i=0;i<n;i++){
      if(v[i]>v[k-1]){
        l=i; break;
      }
    }
        int r=n;
    for(int i=n-1;i>=0;i--){
      if(v[i]<v[k-1]){
        r=i; break;
      }
    }
    if(l!=-1 && r!=n){
      cpy[l]=v[r];
      cpy[r]=v[l];
      ans=max(ans, fun(cpy, k));
    }
    dbg(ans);
  }
  {
    auto cpy=v;
    cpy[0]=v[k-1];
    cpy[k-1]=v[0];
    ans=max(ans, fun(cpy, k));
    dbg(ans);
  }
  {
    for(i=0;i<n;i++){
      if(v[i]<v[k-1]){
        break;
      }
    }
    if(i<n){
      auto cpy=v;
      cpy[i]=v[k-1];
      cpy[k-1]=v[i];
      ans=max(ans, fun(cpy, k));
    }
    dbg(ans);
  }
  {
    for(i=0;i<n;i++){
      if(v[i]>v[k-1]){
        break;
      }
    }
    if(i<n){
      auto cpy=v;
      cpy[i]=v[k-1];
      cpy[k-1]=v[i];
      ans=max(ans, fun(cpy, k));
    }
    dbg(ans);
  }
  cout<<ans;
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
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
  int n, i,k;
  cin >> n>>k;
  deque<int> v(n);
  for (i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  int l=(k+1)/2;
  int r=(k/2);
  for(int i=0;i<n;i++){
    if(v[i]<l){
      l-=v[i];
      v[i]=0;
    }
    else{
      v[i]-=l;
      break;
    }
  } 
    for(int i=n-1;i>=0;i--){
    if(v[i]<r){
      r-=v[i];
      v[i]=0;
    }
    else{
      v[i]-=r;
      break;
    }
  } 
  int cnt=0;
  for(auto z:v)cnt+=(int)(z==0);
  cout<<cnt;
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
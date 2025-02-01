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
int n; string s; cin>>n>>s;
int l,r,lo=0,ro=0,lz=0,rz=0;
l=n/2; r=n/2;
r+=(n&1);
for(int i=0;i<l;i++){
  if(s[i]=='1')lo++;
  else lz++;
}
for(int i=r;i<n;i++){
  if(s[i]=='1')ro++;
  else rz++;
}
int o=0,z=0;
for(auto c:s){
  if(c=='1')o++;
  else z++;
}
while(true){
  dbg(l, lo, lz);
  dbg(r, ro, rz);
  if(lz>=lo && o-lo>=z-lz){
    cout<<l; return;
  }

  if(ro>=rz && z-rz>=o-ro){
    cout<<r; return;
  }

l--;
if(l<0)break;
    if(s[l]=='1'){
    lo--;
  }
  else{
    lz--;
  }
  if(r>=n)break;
  if(s[r]=='1')ro--;
  else rz--;
  r++;
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
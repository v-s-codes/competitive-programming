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

const int mod = 998244353;

// #define googleOrFacebook
// #define testcases
int power(int x, int y){
    int res = 1;
    x = x % mod;
    if (x == 0) return 0; 
    while (y > 0){
        if (y & 1)
            res = (res*x) % mod;
        y = y>>1;
        x = (x*x) % mod;
    }
    return res;
}
int inv(int n){
    return power(n,mod-2);
}
/*
...i1..focus...i2.
(2^(j-i))/(2^j-1);


*/
void solve()
{
  int n; cin>>n;
  vector<vector<int>> vv(n+1, vector<int>(n+1, 0));
  vv[1][1]=1;
  for(int j=2;j<=n;j++){
    for(int i=1;i<=j;i++){
      //1...i-1 2^(j-1)+2^(j-2)...2^(j-i+1)
      int left=pow(2, i-1)-1; 
      if(left<0)left+=mod;
      (left*=pow(2, j-i+1))%=mod;
      (vv[j][i]+=((left*vv[j-1][i-1])%mod))%=mod;
      //i+1...j
      int right = pow(2, j-i)-1; if(right<0)right+=mod;
      (vv[j][i]+=((right*vv[j-1][i])%mod))%=mod;
      int tot=pow(2, j)-1; if(tot<0)tot+=mod;
      int ii=inv(tot);
      (vv[j][i]*=ii)%=mod;
    }
    dbg(vv[j]);
  }
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
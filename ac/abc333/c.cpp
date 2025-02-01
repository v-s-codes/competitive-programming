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
    i=1;
    while(true){
      int tot=(i*(i+1))/2;
      if(tot<n){
        n-=tot;
        i++;
        continue;
      }
      int j=1;
      while(true){
        if(j<n){
          n-=j;
          j++;
          continue;
        }
        int x=(pow(10,i)-1)/9;
        int y=(pow(10,j)-1)/9;
        int z=(pow(10,n)-1)/9;
        cout<<x+y+z;
        dbg(x,y,z);
        dbg(i,j,n);
        return;
      }
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
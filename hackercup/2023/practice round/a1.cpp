#include "bits/stdc++.h"
using namespace std;
#define int long long

#ifdef LOCAL
#include "lib/debug.h"
#define dbg(...)                                                              \
  cerr << "Line " << __LINE__ << ": " FOR_EACH_MACRO(out, __VA_ARGS__) << "\n"
#else
#define dbg(...) 69
#endif

const int mod=1e9+7;

#define googleOrFacebook
#define testcases

void solve(){
  int s,d,k;
  cin>>s>>d>>k;
  int buns = (s+d)*2;
  int cheeseAndPatty = s+2*d;
  dbg(buns, cheeseAndPatty);
  if(k <= cheeseAndPatty && buns>= k+1){
    cout<<"YES"; return;
  }
  cout<<"NO";
    dbg("SEX");
}

signed main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout);
    #endif
    int tt=1,t=1;
    #ifdef testcases
        cin>>tt;
    #endif
    while(t<=tt){
        #ifdef googleOrFacebook
            cout<<"Case #"<<t<<": ";
        #endif
        solve(); cout<<"\n"; t++;
    }
    return 0;
}
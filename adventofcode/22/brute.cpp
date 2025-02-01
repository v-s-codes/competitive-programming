/*
ॐ भूर् भुवः स्वः । तत् सवितुर्वरेण्यं । भर्गो देवस्य धीमहि । धियो यो नः प्रचोदयात् ॥
*/
#pragma GCC optimize("Ofast") 
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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

// #define googleOrFacebook
#define testcases


void solve(){
    int n; cin>>n;
    
}

signed main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    // #ifdef LOCAL
    //     freopen("input.txt", "r", stdin); 
    //     freopen("output.txt", "w", stdout);
    // #endif
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
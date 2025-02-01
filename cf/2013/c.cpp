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
  int n, i,x;
  cin >> n;

  string suf="",pre="";
  cout<<"? 0\n"; cout.flush();
  cin>>x;
  if(!x){
    suf=string(n, '1');
    cout<<"! "<<suf<<"\n"; cout.flush();
    return;
  }
  suf.push_back('0');
  while(suf.size()<n){
    cout<<"? "<<suf<<"0\n"; cout.flush();
    cin>>x;
    if(x){
      suf.push_back('0');
    } else{
      cout<<"? "<<suf<<"1\n"; cout.flush();
      cin>>x;
      if(x){
        suf.push_back('1');
      } else{
        break;
      }
    }
  }
  while((pre.size()+suf.size())<n){
    cout<<"? 0"<<pre<<suf<<"\n"; cout.flush();
    cin>>x;
    if(x){
      pre="0"+pre;
    } else{
      pre="1"+pre;
    }
  }
  cout<<"! "<<pre<<suf<<"\n"; cout.flush();
  dbg("SEX");
}

signed main()
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
// #ifdef LOCAL
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
// #endif
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
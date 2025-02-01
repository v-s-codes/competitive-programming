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
  int n, i;
  cin >> n;
  vector<int> v(n);
  for (i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  int sm=v.back();
  int lst=v.back();
  int nxt=v.back();
  for(i=n-2;i>=0;i--){
    sm+=v[i];
    if(v[i]>nxt){
      int sm1=v[i]+nxt;
      if((sm1/2)<=(sm/(n-i))){
        nxt=(sm1/2);
      } else{
        nxt=(sm/(n-i));
      }
      lst=(sm+n-i-1)/(n-i);
    } else{
      nxt=v[i];
    }
  }
  cout<<lst-nxt;
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
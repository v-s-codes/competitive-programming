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
  int n, m;  cin>>n>>m;
  vector<string> s(n), t(m);
  for(int a=0;a<n;a++) cin>>s[a];
  for(int a=0;a<m;a++) cin>>t[a];
  for(int a=0;a<n;a++)
  {
    if(a+m>n)break;
    for(int b=0;b<n;b++)
    {
      if(b+m>n)break;
      bool f=false;
      for(int al=0;al<m;al++){
        for(int bl=0;bl<m;bl++){
          if(s[a+al][b+bl]!=t[al][bl]){
            f=true;
            break;
          }
        }
        if(f)break;
      }
      if(!f){
        cout<<a+1<<" "<<b+1;
        return;
      }
    }
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
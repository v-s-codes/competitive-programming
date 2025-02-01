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
  int n,m,q;
  cin >> n>>m>>q;
  vector<int> a(q);
  set<int> s;
  for (int i = 0; i < q; i++)
  {
    cin >> a[i];
  }
  s.insert(m);
  for(int i=0;i<q;i++){
    set<int> cpy;
    if(s.size()==n){
      cout<<n<<" "; continue;
    }
    for(auto z:s){
      if(z==a[i]){
        cpy.insert(1); cpy.insert(n);
      } else if(z>a[i]){
        cpy.insert(z-1); cpy.insert(z);
      } else{
        cpy.insert(z); cpy.insert(z+1);
      }
    }
    // dbg(cpy);
    cout<<cpy.size()<<" ";
    s=cpy;
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
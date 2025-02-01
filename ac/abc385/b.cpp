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
  int h,w,x,y; cin>>h>>w>>x>>y;
  vector<string> v(h);
  for(int i=0;i<h;i++) cin>>v[i];
  string t; cin>>t;
  set<pair<int,int>> s;
  x--; y--;
  for(auto c:t){
    if(c=='U'){
      if(x-1>=0 && (v[x-1][y]=='.' || v[x-1][y]=='@')) x--;
    }
    if(c=='D'){
      if(x+1<h && (v[x+1][y]=='.' || v[x+1][y]=='@')) x++;
    }
    if(c=='L'){
      if(y-1>=0 && (v[x][y-1]=='.' || v[x][y-1]=='@')) y--;
    }
    if(c=='R'){
      if(y+1<w && (v[x][y+1]=='.' || v[x][y+1]=='@')) y++;
    }
    if(v[x][y]=='@')s.insert({x,y});
  }
  cout<<x+1<<" "<<y+1<<" "<<((int)s.size())<<"\n";
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
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
  int n;
  cin >> n;
  string a="";
  string e="";
  string i = "";
  string o = "";
  string u = "";
  int x=n/5;
  for(int j=0;j<x;j++)
  {
    a+="a";
    e+="e";
    i+="i";
    o+="o";
    u+="u";
  }
  int y=n%5;
  if(y==1)
  {
    a+="a";
  }
  else if(y==2)
  {
    a+="a";
    e+="e";
  }
  else if(y==3)
  {
    a+="a";
    e+="e";
    i+="i";
  }
  else if(y==4)
  {
    a+="a";
    e+="e";
    i+="i";
    o+="o";
  }
  cout<<a<<e<<i<<o<<u;
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
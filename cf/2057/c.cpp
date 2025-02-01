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

// const int mod = 1e9 + 7;

// #define googleOrFacebook
// #define testcases

vector<int> fun(int n)
{
  vector<int> ans;
  for (int i = 0; i < 32; i++)
  {
    ans.push_back(n & 1);
    n >>= 1;
  }
  return ans;
}

int nuf(vector<int> v)
{
  int ans = 0;
  for (int i = 0; i < 32; i++)
  {
    ans += (v[i] << i);
  }
  return ans;
}
void solve()
{
  int l, r;
  cin >> l >> r;
  vector<int> a = fun(l), b = fun(r);
  vector<int> al, be;
  for (int i = 31; i >= 0; i--)
  {
    if (a[i] != b[i])
    {

      al.push_back(1);
      while (al.size() < 32)
      {
        al.push_back(0);
      }
      be.push_back(0);
      while (be.size() < 32)
      {
        be.push_back(1);
      }

      reverse(al.begin(), al.end());
      reverse(be.begin(), be.end());

      int mx=nuf(al), mn=nuf(be);
      if(l==mn){
        if(mn>=l && mn<=r && mx>=l && mx<=r){
          cout<<(r^mn)+(mn^mx)+(mx^r);
        }
      }
      else{
        if(mx>=l && mx<=r && mn>=l && mn<=r){
          cout<<(l^mn)+(mn^mx)+(mx^l);
        }
      }
      return;
    }
    al.push_back(a[i]);
    be.push_back(a[i]);
  }
  // cout<<nuf(al)<<" "<<nuf(be)<<" "<<nuf(ga);
  // dbg("SEX");
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

/*
1000
0101

1000
0111
0110

01
11


10
01
11
*/
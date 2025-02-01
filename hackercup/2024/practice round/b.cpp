#include "bits/stdc++.h"
#include "iomanip"
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

#define googleOrFacebook
#define testcases

void solve()
{
  long double n,p; cin>>n>>p;
  // (p1/100)^n>=(p/100)^(n-1)
  // p1/100>=(p/100)^((n-1)/n)
  // p1>=((p/100)^((n-1)/n))*100
  cout<<fixed<<setprecision(7)<<max((long double)0, (pow(p/100,(n-1)/n)*100-p));
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
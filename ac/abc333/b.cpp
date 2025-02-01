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
  char a,b,c,d; cin>>a>>b>>c>>d;
  int x=min(abs(a-b), 5-abs(a-b));
  int y=min(abs(c-d), 5-abs(c-d));
  if(x==y)cout<<"Yes";
  else cout<<"No";
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
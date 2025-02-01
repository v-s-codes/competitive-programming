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

#define googleOrFacebook
#define testcases

void solve()
{
    int n, i;
    cin >> n;
    vector<int> v(n);
    for (auto &z : v)
    {
        cin >> z;
    }
    sort(v.begin(), v.end());
    if(n==5){
      int ans = (v[4]+v[3])-(v[2]+v[0]);
      ans = max(ans, (v[4]+v[2])-(v[1]+v[0]));
      cout<<fixed<<setprecision(7)<<ans*0.5; return;
    }
    int ans = (v[n-1]+v[n-2])-(v[0]+v[1]);
    cout<<fixed<<setprecision(7)<<ans*0.5; 
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
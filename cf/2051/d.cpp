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
  int n, i,x,y,tot=0;
  cin >> n>>x>>y;
  vector<int> v(n);
  for (i = 0; i < n; i++)
  {
    cin >> v[i];
    tot+=v[i];
  }
  sort(v.begin(),v.end());
  int ans=0;
  int mn=tot-y, mx=tot-x;
  for(int i=0;i<n-1;i++){
    auto lb=lower_bound(v.begin()+i+1,v.end(),mn-v[i]);
    auto ub=upper_bound(v.begin()+i+1,v.end(),mx-v[i]);
    ans+=ub-lb;
  }
  cout<<ans;
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
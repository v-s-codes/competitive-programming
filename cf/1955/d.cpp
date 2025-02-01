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
  int n, i, m, k;
  cin >> n >> m>>k;
  vector<int> v(n);
  for (i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  map<int, int> mp;
  vector<int> u(m);
  for (i = 0; i < m; i++)
  {
    cin >> u[i];
    mp[u[i]]++;
  }
  map<int,int> curr;
  int ans=0;
  for(int i=0;i<m;i++){
    curr[v[i]]++;
  }
  int sm=0;
  for(auto z:curr){
    sm+=min(z.second, mp[z.first]);
  }
  // dbg(mp);
  // dbg(curr, sm);
  if(sm>=k)ans++;
  for(int i=m;i<n;i++){
    int rm=v[i-m];
    int ad=v[i];
    if(curr[rm]<=mp[rm]){
      sm--;
    }
    curr[rm]--;
    if(curr[ad]<mp[ad]){
      sm++;
    }
     curr[ad]++;
    // dbg(curr, sm);
    if(sm>=k)ans++;
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
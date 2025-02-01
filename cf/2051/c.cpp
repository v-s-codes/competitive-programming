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
  int n, i,m,k;
  cin >> n>>m>>k;
  vector<int> v(m);
  for (i = 0; i < m; i++)
  {
    cin >> v[i];
  }
  vector<int> q(k);
  for (i = 0; i < k; i++)
  {
    cin >> q[i];
  }
  if(k<(n-1)){
    string ans(m,'0');
    cout<<ans;
    return;
  }
  if(k==n){
    string ans(m,'1');
    cout<<ans;
    return;
  }
  set<int> s;
  for(int i=0;i<n;i++)s.insert(i+1);
  for(auto z:q)s.erase(z);
  int missing=*s.begin();
  string ans(m,'0');
  for(int i=0;i<m;i++){
    if(v[i]==missing)ans[i]='1';
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
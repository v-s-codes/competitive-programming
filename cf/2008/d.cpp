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
vector<int> v, col;
void fun(int i, int j){
  if(i==j)return;
  col[i]=j;
  fun(v[i], j);
}
void solve()
{
  int n, i;
  cin >> n;
  v.clear(); v.resize(n, -1);
  col.clear(); col.resize(n, -1);
  for (i = 0; i < n; i++)
  {
    cin >> v[i];
    v[i]--;
  }
  string s; cin>>s;
  for(int i=0;i<n;i++){
    if(col[i]==-1){
      col[i]=i;
      fun(v[i], i);
    }
  }
  dbg(col);
  vector<int> cnt(n, 0);
  for(int i=0;i<n;i++){
    if(s[i]=='0'){
      cnt[col[i]]++;
    }
  }
  for(int i=0;i<n;i++){
    cout<<cnt[col[i]]<<" ";
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
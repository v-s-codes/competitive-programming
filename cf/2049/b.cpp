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
  int n, i;
  cin >> n;
  string s; cin>>s;
  vector<int> v(n);
  int fst=-1;
  for(i=0;i<n;i++){
    if(s[i]=='p'){
      fst=i;
      break;
    }
  }
  if(fst==-1){
    cout<<"YES"; return;
  }
  int val=1;
  for(i=fst;i>=0;i--){
    v[i]=val++;
  }
  for(i=fst+1;i<n;i++){
    v[i]=val++;
  }
  dbg(v);
  int fmax=0;
  set<int> st;
  for(int i=n-1;i>=0;i--){
    st.insert(v[i]);
    while(st.count(fmax+1)){
      fmax++;
    }
    if(s[i]=='s'){
      int val=n-i;
      if(val!=fmax){
        cout<<"NO"; return;
      }
    }
    
  }
  cout<<"YES";
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
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
int n, m;
vector<string> v;
map<char,int> mp;
char inv(char c){
  if(c=='C')return 'F';
  return 'C';
}
vector<int> fun(vector<int> state, vector<string> curr, char c){
  // dbg(state, curr, c);
  vector<int> ans(2,0);
  // bool found=0;
  for(int j=0;j<m;j++){
    int i=state[j];
    if(i<0)continue;
      // dbg(i, j);
      if(v[i][j]==c){
        // found=1;
        curr[i][j]=c;
        if(i+3<n && curr[i+3][j]==c && curr[i+2][j]==c && curr[i+1][j]==c){
          ans[mp[c]]++; return ans;
        }
        if(i-3>=0 && curr[i-3][j]==c && curr[i-2][j]==c && curr[i-1][j]==c){
          ans[mp[c]]++; return ans;
        }
        if(j+3<m && curr[i][j+3]==c && curr[i][j+2]==c && curr[i][j+1]==c){
          ans[mp[c]]++; return ans;
        }
        if(j-3>=0 && curr[i][j-3]==c && curr[i][j-2]==c && curr[i][j-1]==c){
          ans[mp[c]]++; return ans;
        }
        if(i+3<n && j+3<m && curr[i+3][j+3]==c && curr[i+2][j+2]==c && curr[i+1][j+1]==c){
          ans[mp[c]]++; return ans;
        }
        if(i-3>=0 && j-3>=0 && curr[i-3][j-3]==c && curr[i-2][j-2]==c && curr[i-1][j-1]==c){
          ans[mp[c]]++; return ans;
        }
        if(i+3<n && j-3>=0 && curr[i+3][j-3]==c && curr[i+2][j-2]==c && curr[i+1][j-1]==c){
          ans[mp[c]]++; return ans;
        }
        if(i-3>=0 && j+3<m && curr[i-3][j+3]==c && curr[i-2][j+2]==c && curr[i-1][j+1]==c){
          ans[mp[c]]++; return ans;
        }
        state[j]--;
        auto currrr= fun(state,curr,inv(c));
        ans[0]+=currrr[0];
        ans[1]+=currrr[1];
      }
  }
  return ans;
}
void solve()
{
  n = 6, m = 7;
  v.clear(); v.resize(n, string(m, '.'));
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  mp.clear(); mp['C']=0; mp['F']=1;
  vector<int> state(m, n-1);
  vector<string> curr(n, string(m, '.'));
  fun(state,curr,'C');
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
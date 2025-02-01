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
vector<int> prime,primes;
void div(int n){
    prime.clear();
    prime.resize(n+1,0);
    prime[1]=1;
    for(int i=2;i<=n;i++){
        if(prime[i]==0){
            for(int j=1;j*i<=n;j++){
                if(prime[i*j]==0)prime[j*i]=i;
            }
        }
    }
}
#define googleOrFacebook
#define testcases

void solve()
{
  int n, i;
  cin >> n;
  int ans=1;
  for(auto z:primes){
    if(z+2>n)break;
    if(prime[z+2]==z+2){
      ans++;
      
    }
  }
  if(ans==1)ans--;
  cout<<ans;
  dbg("SEX");
}

signed main()
{
  div(10000000);
  primes.clear();
  for(int i=2;i<=10000000;i++){
      if(prime[i]==i)primes.push_back(i);
  }
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
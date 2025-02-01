#include "bits/stdc++.h"
using namespace std;

#define int long long
int solve(int n, vector<int> v)
{
  map<int, int> m;
  int ans=0;
  for(auto z:v){
    m[z]++;
    if(m[z]==2)ans++;
  }
  return ans;
}
signed main()
{
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int t = 1;
  cin >> t;
  while (t--)
  {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &z:v)cin>>z;
    cout<<solve(n, v)<<"\n";
  }
  return 0;
}
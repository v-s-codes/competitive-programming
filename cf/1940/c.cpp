#include "bits/stdc++.h"
using namespace std;
#define int long long
bool odd(vector<int> v){
  int i=0, n=v.size();
  while(i+1<n){
    if(v[i+1]>v[i])return false;
    i+=2;
  }
  i=1;
  while(i+1<n){
    if(v[i+1]!=v[i]+1)return false;
    i+=2;
  }
  return true;
}
bool even(vector<int> v){
  int i=1, n=v.size();
  while(i+1<n){
    if(v[i+1]>v[i])return false;
    i+=2;
  }
  i=0;
  while(i+1<n){
    if(v[i+1]!=v[i]+1)return false;
    i+=2;
  }
  return true;
}
void solve(){
  int n; cin>>n;
  vector<int> v(n);
  for(auto &z:v)cin>>z;
  if(n==1){
    int x=v[0]; 
    while(x--){
      cout<<1;
    }
    return;
  }
  if(odd(v)){
    
    return;
  }
  if(even(v)){

    return;
  }
  cout<<-1; return;
}
signed main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t; cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
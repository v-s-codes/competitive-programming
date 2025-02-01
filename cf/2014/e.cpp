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
int n, m, h;
vector<vector<pair<int,int>>> adj;
set<int> a;
vector<int> dist(int source){
  vector<int> d(n, 1e15);
  d[source] = 0;
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  pq.push({0, source});
  vector<int> vis(n, 0);
  while(!pq.empty()){
    auto [w, u] = pq.top(); pq.pop();
    if(vis[u]) continue;
    vis[u] = 1;
    for(auto nb: adj[u]){
      // if(vis[nb.first]) continue;
      auto [v, w] = nb;
      if(d[v] > d[u] + w){
        d[v] = d[u] + w;
        pq.push({d[v], v});
      }
    }
  }
  vector<int> d1(n, 1e15);
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq1;
  for(int i=0;i<n;i++){
    if(a.count(i) && d[i] != 1e15){
      d1[i] = d[i];
      pq1.push({d1[i], i});
    }
  }
  vis.clear(); vis.resize(n, 0);
  while(!pq1.empty()){
    auto [w, u] = pq1.top(); pq1.pop();
    if(vis[u]) continue;
    vis[u] = 1;
    for(auto nb: adj[u]){
      // if(vis[nb.first]) continue;
      auto [v, w] = nb;
      if(d1[v] > d1[u] + w/2){
        d1[v] = d1[u] + w/2;
        pq1.push({d1[v], v});
      }
    }
  }
  for(int i=0;i<n;i++){
    d[i] = min(d[i], d1[i]);
  }
  return d;
}
void solve()
{
  cin>>n>>m>>h;
  adj.clear(); adj.resize(n);
  a.clear();
  for(int i=0;i<h;i++){
    int x; cin>>x;
    a.insert(x-1);
  }
  for(int i=0;i<m;i++){
    int u,v,w; cin>>u>>v>>w;
    u--; v--;
    adj[u].push_back({v,w});
    adj[v].push_back({u, w});
  }
  auto a=dist(0);
  auto b=dist(n-1);
  int sm=1e15;
  for(int i=0;i<n;i++){
    if(a[i] >= 1e15 || b[i] >= 1e15) continue;
    sm=min(sm, max(a[i],b[i]));
  }
  if(sm >= 1e15) sm=-1;
  cout<<sm;
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
#include "bits/stdc++.h"
using namespace std;
#define int long long

#ifdef LOCAL
#include "lib/debug.h"
#define dbg(...)                                                               \
  cerr << "Line " << __LINE__ << ": " FOR_EACH_MACRO(out, __VA_ARGS__) << "\n"
#else
#define dbg(...) 69
#endif

const int mod = 1e9 + 7;

// #define googleOrFacebook
// #define testcases
int n;
vector<vector<int>> graph;
vector<int> vis, p;
int cost(int v) {
  dbg(v);
  vis[v] = 1;
  for (auto z : graph[v]) {
    if (vis[z] != -1) {
      p[v] = z;
      continue;
    }
    vis[v] += cost(z);
  }
  return vis[v];
}
void solve() {
  cin >> n;
  graph.clear();
  graph.resize(n);
  vis.clear();
  vis.resize(n, -1);
  p.clear();
  p.resize(n, -1);
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    graph[x - 1].push_back(y - 1);
    graph[y - 1].push_back(x - 1);
  }
  int ans = cost(0);
  dbg(vis);
  ans = 1;
  int mx = 0;
  for (int i = 1; i < n; i++) {
    if (p[i] == 0) {
      ans += vis[i];
      mx = max(mx, vis[i]);
    }
  }
  cout << ans - mx;
  dbg("SEX");
}

signed main() {
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
  while (t <= tt) {
#ifdef googleOrFacebook
    cout << "Case #" << t << ": ";
#endif
    solve();
    cout << "\n";
    t++;
  }
  return 0;
}
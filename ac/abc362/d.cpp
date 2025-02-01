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
vector<vector<pair<int, int>>> graph;
void solve() {
  int m;
  cin >> n >> m;
  vector<int> a(n);
  graph.clear();
  graph.resize(n);
  for (auto &z : a)
    cin >> z;
  while (m--) {
    int x, y, z;
    cin >> x >> y >> z;
    x--;
    y--;
    graph[x].push_back({y, 2 * z + a[x] + a[y]});
    graph[y].push_back({x, 2 * z + a[x] + a[y]});
  }
  vector<int> dist(n, LLONG_MAX);
  vector<int> done(n, 0);
  dist[0] = 0;
  // -weight, vertex
  priority_queue<pair<int, int>> pq;
  pq.push({0, 0});
  while (!pq.empty()) {
    int a = pq.top().second;
    pq.pop();
    if (done[a]) {
      continue;
    }
    done[a] = 1;
    for (auto u : graph[a]) {
      int b = u.first;
      int w = u.second;
      if (dist[a] + w < dist[b]) {
        dist[b] = dist[a] + w;
        pq.push({-dist[b], b});
      }
    }
  }
  for (int i = 1; i < n; i++) {
    int x = a[0] + a[i] + dist[i];
    cout << x / 2 << " ";
  }
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
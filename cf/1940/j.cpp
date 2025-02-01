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
#define testcases

const int N = 1e5 + 5;

vector dis(2, vector<int>(N));

void djistra(int x) {}

#define tcT template <class T
tcT > using p = priority_queue<T, vector<T>, greater<T>>;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<array<int, 2>>> edges(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u;
    --v;
    edges[u].push_back({v, w});
    edges[v].push_back({u, w});
    // edges.push_back({u, v, w});
  }

  const int inf = 2e9;

  p<pair<int, int>> ds;
  vector<array<int, 2>> dis(n, {inf, inf});

  ds.emplace(0, 0);
  dis[0] = {0, inf};
  while (!ds.empty()) {
    auto [x, u] = ds.top();
    ds.pop();
    cout << x << ' ' << u << '\n';
    cout << dis[u][0] << ' ' << dis[u][1] << "\n";
    for (auto [v, w] : edges[u]) {
      if (dis[v][1] > x + w) {
        dis[v][1] = x + w;
        ds.emplace(dis[v][1], v);
        if (dis[v][0] > dis[v][1])
          swap(dis[v][0], dis[v][1]);
      }
    }
  }

  std::cout << dis[n - 1][0] + dis[n - 1][1] << "\n";
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
  // cin >> tt;
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
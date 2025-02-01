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

int n, c;
vector<vector<int>> adj;
vector<int> gold;
vector<int> dp[2][2];
int fun(int node, int parent, int status, int parent_status) {

  if (dp[status][parent_status][node] != -1)
    return dp[status][parent_status][node];
  int ans = status * gold[node];
  for (auto nb : adj[node]) {
    if (nb == parent)
      continue;
    ans += max(fun(nb, node, 1, status) - 2 * c * status,
               fun(nb, node, 0, status));
  }
  return dp[status][parent_status][node] = ans;
}
void solve() {
  cin >> n >> c;
  adj.clear();
  adj.resize(n);
  gold.clear();
  gold.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> gold[i];
  }
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      dp[i][j].clear(), dp[i][j].resize(n, -1);
  cout << max(fun(0, -1, 1, 0), fun(0, -1, 0, 0));
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
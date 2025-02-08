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
vector<pair<int, int>> subsets;

void DSU(int n) {
  subsets.clear();
  subsets.resize(n, {0, 0});
  for (int i = 0; i < n; i++)
    subsets[i].first = i;
}

int findDSU(int i) {
  if (subsets[i].first != i)
    subsets[i].first = findDSU(subsets[i].first);
  return subsets[i].first;
}

void unionDSU(int x, int y) {
  int xroot = findDSU(x);
  int yroot = findDSU(y);
  if (subsets[xroot].second < subsets[yroot].second)
    subsets[xroot].first = yroot;
  else if (subsets[xroot].second > subsets[yroot].second)
    subsets[yroot].first = xroot;
  else {
    subsets[yroot].first = xroot;
    subsets[xroot].second++;
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  DSU(n);
  set<int> unused_edges;
  vector<pair<int, int>> edges(m);
  for (int i = 0; i < m; i++) {
    cin >> edges[i].first >> edges[i].second;
    edges[i].first--;
    edges[i].second--;
    if (findDSU(edges[i].first) != findDSU(edges[i].second)) {
      unionDSU(edges[i].first, edges[i].second);
    } else {
      unused_edges.insert(i);
    }
  }
  set<int> parents;
  for (int i = 0; i < n; i++) {
    parents.insert(findDSU(i));
  }
  vector<tuple<int, int, int>> ans;
  for (auto i : unused_edges) {
    if (parents.size() == 1) {
      break;
    }
    auto papa = findDSU(edges[i].first);
    for (auto j : parents) {
      if (papa != j) {
        unionDSU(papa, j);
        ans.push_back({i + 1, edges[i].first + 1, j + 1});
        parents.erase(j);
        parents.erase(papa);
        parents.insert(findDSU(edges[i].first));
        break;
      }
    }
  }
  cout << ans.size() << "\n";
  for (auto z : ans) {
    cout << get<0>(z) << " " << get<1>(z) << " " << get<2>(z) << "\n";
  }
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
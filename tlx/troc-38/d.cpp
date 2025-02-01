#include "bits/stdc++.h"
using namespace std;
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;

#define ordered_set                                                            \
  tree<int, null_type, less<int>, rb_tree_tag,                                 \
       tree_order_statistics_node_update>
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
vector<int> invA;
bool opp;
static bool cmp(int a, int b) {
  if (!opp)
    invA[a] < invA[b];
  return invA[a] > invA[b];
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  vector<vector<int>> right(n), left(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    right[x].push_back(y);
    left[y].push_back(x);
  }
  invA.clear();
  invA.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    invA[a[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    opp = false;
    sort(right[i].begin(), right[i].end(), cmp);
    opp = true;
    sort(left[i].begin(), left[i].end(), cmp);
  }
  dbg(left, right);
  vector<vector<int>> who_have_left_at_i(n);
  for (int i = 0; i < n; i++) {
    if (left[i].empty())
      continue;
    who_have_left_at_i[invA[left[i][0]]].push_back(i);
  }
  ordered_set o_set;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (auto z : who_have_left_at_i[i]) {
      o_set.insert(z);
    }
    int j = n - 1;
    if (!right[a[i]].empty()) {
      j = invA[right[a[i]][0]];
    }
    ans += o_set.order_of_key(j + 1) - o_set.order_of_key(i);
  }
  cout << ans;
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
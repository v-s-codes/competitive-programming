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
int n, m;
vector<string> vs;
string narek = "narek";
vector<int> dp[5];
bool inNarek(char c) {
  return c == 'n' || c == 'a' || c == 'r' || c == 'e' || c == 'k';
}
int fun(int i, int jj) {
  if (i == n) {
    return -1 * jj;
  }
  if (dp[jj][i] != -1)
    return dp[jj][i];
  int curr = 0;
  int org = jj;
  for (int j = 0; j < m; j++) {
    if (vs[i][j] == narek[jj]) {
      (jj += 1) %= 5;
      if (jj == 0)
        curr += 5;
    } else if (inNarek(vs[i][j])) {
      curr--;
    }
  }
  return dp[org][i] = max(curr + fun(i + 1, jj), fun(i + 1, org));
}
void solve() {
  cin >> n >> m;
  vs.clear();
  vs.resize(n);
  for (auto &i : vs)
    cin >> i;
  for (int i = 0; i < 5; i++)
    dp[i] = vector<int>(n + 1, -1);
  // dp['.']=vector<int>(n+1,-1);
  cout << fun(0, 0);
  // for(auto &c:narek)
  // {
  //   dbg(fun(5, c));
  // }
  // dbg("SEX");
}

signed main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
#ifdef LOCAL
  freopen("random_input.txt", "r", stdin);
  freopen("my_output.txt", "w", stdout);
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
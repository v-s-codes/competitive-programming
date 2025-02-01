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

#define googleOrFacebook
#define testcases
vector<string> vs, curr;
int n, m;
char mover(vector<int> state, vector<string> vs) {
  int f = 0, c = 0;
  for (int j = 0; j < m; j++) {
    for (int i = state[j]; i < n; i++) {
      if (vs[i][j] == 'F') {
        f++;
      } else if (vs[i][j] == 'C') {
        c++;
      }
    }
  }
  if (c == f)
    return 'F';
  if (c - f == 1)
    return 'C';
  return '.';
}
void solve() {
  n = 6;
  m = 7;
  vs.clear();
  vs.resize(n);
  for (auto &z : vs)
    cin >> z;
  vector<int> state(m, 0);
  for (int i = 1; i < 823543; i++) {
    curr.clear();
    curr.resize(n, string(m, '.'));
    auto val = i;
    int xxx = 0;
    for (int dir = 0; dir < m; dir++) {
      state[xxx++] = n - val % m;
      val /= m;
    }
    for (int x = 0; x < m; x++) {
      for (int y = state[x]; y < n; y++) {
        curr[y][x] = vs[y][x];
      }
    }
    auto c = mover(state, curr);
    if (c == '.')
      continue;
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
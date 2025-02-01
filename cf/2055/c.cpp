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

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(m));
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> v[i][j];
    }
  }
  int sm = 0;
  if (s[0] == 'D') {
    for (int j = 0; j < m; j++) {
      sm += v[0][j];
    }
  } else {
    for (int i = 0; i < n; i++) {
      sm += v[i][0];
    }
  }
  set<pair<int, int>> st;
  int a = 0, b = 0;
  while (a < n && b < m && a + b < n + m - 2) {
    if (s[a + b] == 'D') {
      a++;
    } else {
      b++;
    }
    st.insert({a, b});
  }
  // dbg(st);
  for (int i = 0; i < n; i++) {
    int k = -1;
    int curr = 0;
    for (int j = 0; j < m; j++) {
      curr += v[i][j];
      if (st.find({i, j}) != st.end()) {
        if (k != -1) {
          k = -1;
          break;
        } else {
          k = j;
        }
      }
    }
    dbg(i, k);
    if (k != -1) {
      v[i][k] = sm - curr;
      st.erase({i, k});
    }
  }
  for (int j = 0; j < m; j++) {
    int k = -1;
    int curr = 0;
    for (int i = 0; i < n; i++) {
      curr += v[i][j];
      if (st.find({i, j}) != st.end()) {
        if (k != -1) {
          k = -1;
          break;
        } else {
          k = i;
        }
      }
    }
    if (k != -1) {
      v[k][j] = sm - curr;
      st.erase({k, j});
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << v[i][j] << " ";
    }
    cout << "\n";
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
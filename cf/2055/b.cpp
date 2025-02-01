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
  int n, i;
  cin >> n;
  vector<int> v(n);
  for (i = 0; i < n; i++) {
    cin >> v[i];
  }
  vector<int> u(n, 0);
  for (i = 0; i < n; i++) {
    cin >> u[i];
  }
  i = -1;
  for (int j = 0; j < n; j++) {
    if (v[j] < u[j]) {
      if (i == -1)
        i = j;
      else {
        cout << "NO";
        return;
      }
    }
  }
  // dbg(i);
  if (i == -1) {
    cout << "YES";
    return;
  }
  int diff = u[i] - v[i];
  for (int j = 0; j < n; j++) {
    if (j == i)
      continue;
    if (v[j] - diff < u[j]) {
      cout << "NO";
      return;
    }
  }
  cout << "YES";
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
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
  string s;
  cin >> n >> s;
  for (i = n; i > 0; i--) {
    auto cpy = s;
    int j = 0;
    int ps = 1;
    set<int> op;
    while (j < n) {
      // if(i==3){
      //   dbg(op, j);
      // }
      if (op.count(j - i))
        op.erase(j - i);
      int tot = ((int)(op.size()) & 1);
      int curr = (int)(cpy[j] - '0');
      if (tot ^ curr) {
        cpy[j] = '1';
        j++;
        continue;
      } else if (j + i <= n) {
        op.insert(j);
        cpy[j] = '1';
        j++;
      } else {
        ps = 0;
        break;
      }
    }
    if (ps) {
      cout << i;
      return;
    }
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
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
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> v;
  int rem = n;
  if (n == 4) {
    if ((x == 1 && y == 2) || (x == 1 && y == 4) || (x == 2 && y == 3) ||
        (x == 3 && y == 4)) {
      cout << "0 1 0 1";
      return;
    }
    if (x == 1 && y == 3) {
      cout << "0 2 1 2";
      return;
    }
    cout << "2 0 2 1";
    return;
  }
  x--;
  y--;
  if (n % 2) {
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    rem = n - 3;
  } else {
    v.push_back(2);
    v.push_back(0);
    v.push_back(2);
    v.push_back(1);
    rem = n - 4;
  }
  for (int i = 0; i < (rem / 2); i++) {
    v.push_back(0);
    v.push_back(1);
  }
  dbg(v);
  int i = 0;
  while (i < n) {
    // i -> 0
    // x+i -> x, or i-x -> x
    // y+i -> y, or i-y -> y
    int lo = (i + x) % n;
    int hi = (i + y) % n;
    if (v[lo] != v[hi]) {
      int k = i;
      dbg(i, "cw");
      while (true) {
        cout << v[k] << " ";
        (k += 1) %= n;
        if (k == i) {
          break;
        }
      }
      break;
    }
    lo = (i - x + n) % n;
    hi = (i - y + n) % n;
    if (v[lo] != v[hi]) {
      int k = i;
      dbg(i, "acw");
      while (true) {
        cout << v[k] << " ";
        (k += (n - 1)) %= n;
        if (k == i) {
          break;
        }
      }
      break;
    }
    i++;
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
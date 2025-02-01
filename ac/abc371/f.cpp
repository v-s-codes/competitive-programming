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
int changingFun(int x, int y) {
  return (x + y); // res bhi change krna h......
}

const int N = 5e5; // limit for array size
int n;             // array size
int t[2 * N];

void build() { // build the tree
  for (int i = n - 1; i > 0; --i)
    t[i] = changingFun(t[i << 1], t[i << 1 | 1]);
}

void modify(int p, int value) { // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1)
    t[p >> 1] = changingFun(t[p], t[p ^ 1]);
}

int query(int l, int r) { // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1)
      res = changingFun(res, t[l++]);
    if (r & 1)
      res = changingFun(res, t[--r]);
  }
  return res;
}
int minMovesOnRight(int in, int pos) {
  int lo = in, hi = n, mid;
  while (lo < hi) {
    mid = (lo + hi) / 2;
    int mnPos = pos + (mid - in);
    if (mnPos <= query(mid, mid + 1)) {
      hi = mid;
    } else
      lo = mid + 1;
  }
  int sm = ((lo - in) * (2 * pos + (lo - in - 1))) / 2;
  int ans = sm - (query(in, lo));
  modify(in, pos);
}
int minMovesOnLeft(int in, int pos) {
  int lo = -1, hi = in, mid;
  while (lo < hi) {
    mid = (lo + hi + 1) / 2;
    int mnPos = pos - (in - mid);
    if (mnPos >= v[mid]) {
      lo = mid;
    } else
      hi = mid - 1;
  }
  int sm = ((in - lo) * (2 * pos - (in - lo - 1))) / 2;
  return (pre[in + 1] - pre[lo + 1]) - sm;
}
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  build();
  int q;
  cin >> q;
  int ans = 0;
  while (q--) {
    int in, pos;
    cin >> in >> pos;
    in--;
    auto qq = query(in, in + 1);
    if (qq <= pos) {
      ans += minMovesOnRight(in, pos);
    } else
      ans += minMovesOnLeft(in, pos);
    cout << ans << "\n";
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
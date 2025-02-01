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

void solve() {
  int n;
  cin >> n;
  priority_queue<int> v;
  int cnt = 0;
  int p = 2;
  int tot = 0;
  while (p * p <= n) {
    while (n % p == 0) {
      v.push(-p);
      tot += p;
      cnt++;
      n /= p;
    }
    p++;
  }
  if (n != 1)
    v.push(-n), tot += n, cnt++;
  if (tot > 41) {
    cout << -1;
    return;
  }
  while (tot < 41 && !v.empty()) {
    int x = v.top();
    v.pop();
    if (v.empty()) {
      v.push(x);
      break;
    }
    int y = v.top();
    v.pop();
    if (tot + x + y + x * y <= 41) {
      v.push(-1 * x * y);
      tot += x + y + x * y;
      cnt--;
    } else {
      v.push(x);
      v.push(y);
      break;
    }
  }
  while (tot < 41)
    v.push(-1), tot++, cnt++;
  cout << cnt << " ";
  while (!v.empty())
    cout << -1 * v.top() << " ", v.pop();
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
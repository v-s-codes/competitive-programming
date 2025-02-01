#include "bits/stdc++.h"
using namespace std;
#define int long long

#ifdef LOCAL
#include "lib/debug.h"
#define dbg(...) \
  cerr << "Line " << __LINE__ << ": " FOR_EACH_MACRO(out, __VA_ARGS__) << "\n"
#else
#define dbg(...) 69
#endif

const int mod = 1e9 + 7;

// #define googleOrFacebook
// #define testcases

void solve()
{
  int n, q;
  cin >> n >> q;
  map<int, set<int>> mp;
  map<int, int> parent;
  for (int i = 0; i < n; i++)
  {
    mp[i + 1].insert(i + 1);
    parent[i + 1] = i + 1;
  }
  int ans = 0;
  while (q--)
  {
    int type;
    cin >> type;
    if (type == 2)
    {
      cout << ans << "\n";
      continue;
      ;
    }
    int p, h;
    cin >> p >> h;
    auto j = parent[p];
    parent[p] = h;
    mp[j].erase(p);
    mp[h].insert(p);
    if (mp[j].size() == 1)
      ans--;
    if (mp[h].size() == 2)
      ans++;
  }
  dbg("SEX");
}

signed main()
{
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
  while (t <= tt)
  {
#ifdef googleOrFacebook
    cout << "Case #" << t << ": ";
#endif
    solve();
    cout << "\n";
    t++;
  }
  return 0;
}
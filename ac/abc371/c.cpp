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

    int n;
    cin >> n;
    int mg;
    cin >> mg;
    vector<vector<int>> g(n, vector<int>(n, 0));
    while (mg--)
    {
      int a, b;
      cin >> a >> b;
      g[a - 1][b - 1] = 1;
      g[b - 1][a - 1] = 1;
    }
    int mh;
    cin >> mh;
    vector<vector<int>> h(n, vector<int>(n, 0));
    while (mh--)
    {
      int a, b;
      cin >> a >> b;
      h[a - 1][b - 1] = 1;
      h[b - 1][a - 1] = 1;
    }
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n - i - 1; j++)
      {
        cin >> a[i][i + 1 + j];
      }
    }
    vector<int> p;
    for (int i = 0; i < n; i++)
    {
      p.push_back(i);
    }
    int mn = 1e18;
    // p = {3, 0, 1, 4, 2};
    // dbg(a);
    do
    {
      int ans = 0;
      // vector<pair<int,int>> vp;
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j <= i; j++)
        {
          if (g[i][j] != h[p[i]][p[j]])
          {
            // dbg(i, j, p[i], p[j], a[min(p[i], p[j])][max(p[j], p[i])]);
            ans += a[min(p[i], p[j])][max(p[j], p[i])];
            // vp.push_back({max(i, j), min(i, j)});
          }
        }
      }
      //     if(mn>ans)
      // dbg(vp, ans,p);
      mn = min(mn, ans);
      // break;

    } while (next_permutation(p.begin(), p.end()));
    cout << mn;
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
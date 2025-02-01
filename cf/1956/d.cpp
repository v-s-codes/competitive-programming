#include "bits/stdc++.h"
using namespace std;

#define int long long
vector<int> v;
vector<pair<int, int>> vp;
void fun(int l, int r)
{
  // cout<<"start\n";
  // cout<<l<<" "<<r<<"\t lr\n";

  // for(auto z:vp)cout<<z.first<<" "<<z.second<<"\n";
  // cout<<"done\n";
  if (r + 1 < l)
  {
    // cout << l << " " << r << "\trund\n";
    return;
  }
  // cout<<l<<" "<<r<<" "<<"\tfjsjdf\n";
  if (l == 1)
    return;
  fun(l - 1, r);
  vp.push_back({r - l + 2, r + 1});
  for (int i = 1; i < l; i++)
  {
    vp.push_back({r - i + 1, r - i + 1});
  }
  fun(l - 1, r - 1);
}
void solve()
{
  int n;
  cin >> n;
  v.clear();
  v.resize(n);
  vp.clear();
  for (auto &z : v)
    cin >> z;
  int ans = 0;
  vector<int> fin;
  int val = -1;
  for (int i = 0; i < (1 << n); i++)
  {
    vector<int> ind({-1});
    int curr = 0;
    for (int j = 0; j < n; j++)
    {
      if ((1 << j) & i)
      {
        ind.push_back(j);
        curr += v[j];
      }
    }
    ind.push_back(n);
    int al = ind.size();
    for (int j = 1; j < al; j++)
    {
      curr += (ind[j] - ind[j - 1] - 1) * (ind[j] - ind[j - 1] - 1);
    }
    if (curr > ans)
    {
      ans = curr;
      fin = ind;
      val = i;
    }
  }
  // for (auto be : fin)
  //   cout << be << " ";
  // cout << "\n";
  // cout<<val<<"\n";
  for (int i = 0; i < n; i++)
  {
    // cout<<i<<" "<<(!((1 << i) & val))<<" "<<v[i]<<"\tjfsdf\n";
    if ((!((1 << i) & val)) && v[i])
      vp.push_back({i + 1, i + 1});
    // for(auto z:vp)cout<<z.first<<" "<<z.second<<" "; cout<<"\n";
  }
  int al = fin.size();
  // vp.clear();
  for (int i = 1; i < al; i++)
  {
    if (fin[i] - 1 >= fin[i - 1] + 1)
    {
      fun(fin[i] - fin[i - 1] - 1, fin[i] - 1);
      vp.push_back({fin[i - 1] + 2, fin[i]});
    }
  }
  cout << ans << " " << ((int)(vp.size())) << "\n";
  for (auto z : vp)
    cout << z.first << " " << z.second << "\n";
}
signed main()
{
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int t = 1;
  // cin >> t;
  while (t--)
  {
    solve();
    cout << "\n";
  }
  return 0;
}
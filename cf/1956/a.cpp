#include "bits/stdc++.h"
using namespace std;

#define int long long
vector<int> solve(int k, int q, vector<int> a, vector<int> n) {
  sort(a.begin(), a.end());
  vector<int> ans;
  for (auto ni : n) {
    ans.push_back(min(a[0] - 1, ni));
  }
  return ans;
}
signed main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int t = 1;
  cin >> t;
  while (t--) {
    int k, q;
    cin >> k >> q;
    vector<int> a(k), n(q);
    for (auto &z : a)
      cin >> z;
    for (auto &z : n)
      cin >> z;
    auto ans = solve(k, q, a, n);
    for (auto z : ans)
      cout << z << " ";
    cout << "\n";
  }
  return 0;
}
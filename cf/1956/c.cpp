#include "bits/stdc++.h"
using namespace std;

#define int long long
void solve(int n) {
  cout << ((n * (n + 1) * (2 * n + 1)) / 3 - (n * (n + 1)) / 2) << " " << 2 * n
       << "\n";
  for (int i = 0; i < n; i++) {
    cout << "1 " << (n - i) << " ";
    for (int j = 0; j < n; j++)
      cout << j + 1 << " ";
    cout << "\n";
    cout << "2 " << (n - i) << " ";
    for (int j = 0; j < n; j++)
      cout << j + 1 << " ";
    cout << "\n";
  }
}
signed main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    solve(n);
    cout << "\n";
  }
  return 0;
}
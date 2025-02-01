#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
  int n;
  cin >> n;
  int o = 0, z = 0, mn = LLONG_MAX, tot = 0;
  while (n--) {
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (auto c : s) {
      if (c == '0')
        a++;
      else
        b++;
    }
    tot += min(a, b);
    if (a > b)
      z++;
    else if (a < b)
      o++;
    else {
      z++;
      o++;
    }
    mn = min(mn, max(a, b) - min(a, b));
  }
  if ((z && o) || tot == 0) {
    cout << tot;
  } else {
    cout << tot + mn;
  }
  return 0;
}
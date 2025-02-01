#include "bits/stdc++.h"
using namespace std;
#define int long long
bool odd(vector<int> v) {
  int i = 0, n = v.size();
  while (i + 1 < n) {
    if (v[i + 1] > v[i])
      return false;
    i += 2;
  }
  i = 1;
  while (i + 1 < n) {
    if (v[i + 1] != v[i] + 1)
      return false;
    i += 2;
  }
  return true;
}
bool even(vector<int> v) {
  int i = 1, n = v.size();
  while (i + 1 < n) {
    if (v[i + 1] > v[i])
      return false;
    i += 2;
  }
  i = 0;
  while (i + 1 < n) {
    if (v[i + 1] != v[i] + 1)
      return false;
    i += 2;
  }
  return true;
}

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &z : v)
    cin >> z;

  int mn = 169, mi = -1;
  for (int i = n - 1; ~i; --i) {
    if (mn > v[i]) {
      mn = v[i];
      mi = i;
    }
  }

  long long ans = 0;

  auto ck = [&]() {
    for (int i = 0; i < n; ++i) {
      for ()
    }
  };

  if (mi != 0) {
    int diff = v[mi - 1] - v[mi];
    int con = diff + 1;
    int rem = v[mi - 1] - con;
    int x = (1ll << rem);
    x -= 1;
    x *= (1ll << (con + 1));
    x += (1ll << con);
    ans = x - mi;
  } else {
  }
}
signed main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
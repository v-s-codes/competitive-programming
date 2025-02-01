#include "bits/stdc++.h"
#include "random"
using namespace std;

mt19937 rng;

int main() {
  rng.seed(time(0));
  int t = rng() % 10 + 1;
  cout << t << endl;
  while (t--) {
    int n = rng() % 10 + 1;
    cout << n << endl;
    for (int i = 0; i < n; i++) {
      cout << rng() % 10 + 1 << " ";
    }
    cout << endl;
  }
  return 0;
}
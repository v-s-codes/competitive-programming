#include "bits/stdc++.h"
#include "random"
using namespace std;

mt19937 rng;

int main() {
  rng.seed(time(0));
  int n = rng() % 10;
  int delta = rng() % 10 + 2;
  cout << n << " " << n + delta << "\n";
  return 0;
}
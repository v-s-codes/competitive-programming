#include <bits/stdc++.h>
using namespace std;

mt19937 rng;

int main(int argc, char const *argv[]) {
  rng.seed(atoi(argv[1]));
  int n = rng() % 20 + 1;
  cout << n << "\n";
  set<int> st;
  while (st.size() < n) {
    st.insert(rng() % (2 * n) + 1);
  }
  for (auto z : st) {
    cout << z << " " << rng() % (2 * n) + 1 << "\n";
  }
  return 0;
}
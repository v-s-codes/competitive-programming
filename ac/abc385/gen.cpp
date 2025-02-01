#include "bits/stdc++.h"
#include "random"
using namespace std;

mt19937 rng;

int main()
{
//   freopen("input.txt", "w", stdout);
    unsigned int seed = static_cast<unsigned int>(time(nullptr));
    rng.seed(seed);
    int n = 1 + rng() % 10;
    int m = 1 + rng() % 10;
    int sx = 1 + rng() % 10;
    int sy = 1 + rng() % 10;
    cout << n << " " << m << " " << sx << " " << sy << endl;
    for (int i = 0; i < n; i++)
    {
        cout << 1 + rng() % 10 << " " << 1 + rng() % 10 << endl;
    }
    string dir = "LRUD";
    for (int i = 0; i < m; i++)
    {
        cout << dir[rng() % 4] << " " << 1 + rng() % 10 << endl;
    }
    return 0;
}
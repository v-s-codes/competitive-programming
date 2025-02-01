#include "bits/stdc++.h"
#include <random>
using namespace std;

mt19937 rng;

int main(int argc, char const *argv[])
{
    rng.seed(atoi(argv[1]));
    string x = "narek";
    int n = rng() % 15 + 1;
    cout << n << " ";
    int m = rng() % 15 + 1;
    cout << m << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << x[rng() % 5];
        }
        cout << "\n";
    }
    return 0;
}
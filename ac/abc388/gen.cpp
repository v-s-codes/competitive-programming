#include "bits/stdc++.h"
#include "random"
using namespace std;

mt19937 rng;

int main(){
	rng.seed(time(0));
    int n=rng()%10+1;
    cout<<n<<"\n";
    int x=1;
    for(int i=0;i<n;i++){
        x+=rng()%7;
        cout<<x<<" ";
    }
	return 0;
}
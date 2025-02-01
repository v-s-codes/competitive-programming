#include "bits/stdc++.h"
using namespace std;
#define int long long

#ifdef LOCAL
#include "lib/debug.h"
#define dbg(...) \
    cerr << "Line " << __LINE__ << ": " FOR_EACH_MACRO(out, __VA_ARGS__) << "\n"
#else
#define dbg(...) 69
#endif


// #define googleOrFacebook
// #define testcases

void solve()
{
    int tot=237;
    set<string> ss;
    while(tot--){
        string x; cin>>x;
        ss.insert(x);
        // dbg(x);
    }
    tot=0;
    string curr="";
    string chainName = "";
    string brandCode="";
    string brandName="";
    string file = "";
    for(int i=238;i<240;i++){
        string s;
        getline(cin, s);
        file+=s;
    }
    int n=file.size();
    int i=0;
    // n=1000;
    // dbg(file);
    while(i<n){
        // dbg(i, tot, file[i]);
        if(file[i]=='{'){
            tot++;
            i++;
            continue;
        }
        if(file[i]=='}'){
            tot--;
            i++;
            continue;
        }
        if(tot!=2 && tot!=4){
            i++;
            continue;
        }
        if(tot==2){
            if(file[i]=='n' && file.substr(i+1, 6)=="ame\":\""){
                chainName.clear();
                i+=7;
                while(i<n){
                    if(file[i]=='\"'){
                        i++;
                        break;
                    }
                    chainName.push_back(file[i++]);
                }
            }
            else i++;
        }
        else{
            if(file[i]=='i' && file.substr(i+1, 4)=="d\":\""){
                brandCode.clear(); brandName.clear();
                i+=5;
                while(i<n){
                    if(file[i]=='\"'){
                        i+=1;
                        break;
                    }
                    brandCode.push_back(file[i++]);
                }
                while(file[i]!='\"')i++;
                i++;
                while(file[i]!='\"')i++;
                i++;
                while(file[i]!='\"')i++;
                i++;
                while(i<n){
                    if(file[i]=='\"'){
                        i+=1;
                        break;
                    }
                    brandName.push_back(file[i++]);
                }
                if(!ss.count(brandCode)){
                    for(auto z:brandCode){
                        if(z==',')cout<<" ";
                        else cout<<z;
                    }
                    cout<<", ";
                    for(auto z:brandName){
                        if(z==',')cout<<" ";
                        else cout<<z;
                    }
                    cout<<", ";
                    for(auto z:chainName){
                        if(z==',')cout<<" ";
                        else cout<<z;
                    }
                    cout<<"\n";
                }
            }
            else i++;
        }
    }
    
    dbg("done");
}

signed main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tt = 1, t = 1;
#ifdef testcases
    cin >> tt;
#endif
    while (t <= tt)
    {
#ifdef googleOrFacebook
        cout << "Case #" << t << ": ";
#endif
        solve();
        cout << "\n";
        t++;
    }
    return 0;
}
#include "bits/stdc++.h"
using namespace std;
#define int long long

#ifdef LOCAL
#include "lib/debug.h"
#define dbg(...)                                                               \
  cerr << "Line " << __LINE__ << ": " FOR_EACH_MACRO(out, __VA_ARGS__) << "\n"
#else
#define dbg(...) 69
#endif

const int mod = 1e9 + 7;

// #define googleOrFacebook
// #define testcases

void print(int a, int b, int c) {
  vector<int> v = {a, b, c};
  sort(v.begin(), v.end());
  for (auto z : v) {
    cout << z << " ";
  }
}
void solve() {
  int n, i, x;
  cin >> n >> x;
  vector<int> v(n);
  vector<set<int>> mp(x + 1);
  set<int> us;
  for (i = 0; i < n; i++) {
    cin >> v[i];
    mp[v[i]].insert(i + 1);
    us.insert(v[i]);
  }
  if (x % 3 == 0) {
    int y = x / 3;
    if (mp[y].size() >= 3) {
      int cnt = 0;
      vector<int> ans;
      for (auto z : mp[y]) {
        if (cnt == 0) {
          ans.push_back(z);
          cnt++;
        } else if (cnt == 1) {
          ans.push_back(z);
          cnt++;
        } else if (cnt == 2) {
          ans.push_back(z);
          break;
        }
      }
      print(ans[0], ans[1], ans[2]);
      return;
    }
  }
}
{
  for (i = 0; i < n; i++) {
    int al = x - 2 * v[i];
    if (al != v[i] && al > 0 && al <= x) {
      if (mp[v[i]].size() >= 2 && mp[al].size() >= 1) {
        int cnt = 0;
        vector<int> ans;
        for (auto z : mp[v[i]]) {
          if (cnt == 0) {
            ans = {z};
            cnt++;
          }
          cnt++;
        }
        else if (cnt == 1) {
          ans.push_back(z);
          cnt++;
          break;
        }
      }
      for (auto z : mp[al]) {
        ans.push_back(z);
        print(ans[0], ans[1], ans[2]);
        return;
      }
    }
  }
}

vector<int> u;
for (auto z : us) {
  u.push_back(z);
}
// if(us.size()<=1000){
//   int _n=u.size();
//   for(int i=0;i<_n;i++){
//     for(int j=i+1;j<_n;j++){
//       int al=x-u[i]-u[j];
//       if(al>0 && al<=x && u[i]!=u[j] && u[i]!=al && al!=u[j] &&
//       mp[al].size()>0){
//         cout<<(*mp[u[i]].begin())<<" "<<(*mp[u[j]].begin())<<"
//         "<<(*mp[al].begin()); return;
//       }
//       }
//   }
// }
n = u.size();
set<int> t2, f2, s;
for (int i = 0; i < 2 * x; i++) {
  f2.insert(i);
}

for (i = 0; i < n; i++) {
  // dbg(t2, f2);
  s.insert(u[i]);
  if (t2.count(x - u[i])) {
    for (int j = 0; j < i; j++) {
      int al = x - u[j] - u[i];
      if (al > 0 && al <= x && u[i] != u[j] && u[i] != al && al != u[j] &&
          mp[al].size() > 0) {
        cout << (*mp[u[j]].begin()) << " " << (*mp[u[i]].begin()) << " "
             << (*mp[al].begin());
        return;
      }
    }
  }
  if (i <= 1000) {
    for (int j = 0; j < i; j++) {
      int y = u[i] + u[j];
      if (y > 0 && y <= 2 * x) {
        t2.insert(y);
        f2.erase(y);
      }
    }
  } else {
    set<int> temp;
    for (auto z : f2) {
      int al = z - u[i];
      if (al > 0 && al <= x && u[i] != al && s.count(al)) {
        temp.insert(z);
      }
    }
    for (auto z : temp) {
      f2.erase(z);
      t2.insert(z);
    }
  }
}
cout << -1;
dbg("SEX");
}

signed main() {
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
  while (t <= tt) {
#ifdef googleOrFacebook
    cout << "Case #" << t << ": ";
#endif
    solve();
    cout << "\n";
    t++;
  }
  return 0;
}
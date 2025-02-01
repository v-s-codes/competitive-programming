#include <bits/stdc++.h>

using namespace std;

void solve() {
  // cout<<"hello";
  int n;
  cin >> n;
  vector<int> v(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> v[i];
  vector<int> ai(n + 1);
  for (int i = 1; i <= n; i++)
    ai[v[i]] = i;
  set<int> st;
  vector<int> q(n + 1, -1);
  vector<vector<int>> curr, fin;
  vector<int> x;
  // for(int i=1;i<=n;i++)cout<<ai[i]<<"\n";
  for (int i = 1; i <= n; i++) {
    if (st.count(i))
      continue;
    vector<int> temp;
    temp.push_back(i);
    st.insert(i);
    // cout<<temp.back()<<" "<<ai[temp.back()]<<"\n";
    while (!st.count(ai[temp.back()])) {
      st.insert(ai[temp.back()]);
      temp.push_back(ai[temp.back()]);
    }
    // for(auto z:st)cout<<z<<" @\t"; cout<<"\n";
    if (temp.size() == 1) {
      // for(auto z:temp)cout<<z<<"sdfsdjkf\t"; cout<<'\n';
      x.push_back(temp[0]);
    } else if (temp.size() == 2) {
      curr.push_back(temp);
    } else {
      fin.push_back(temp);
    }
  }
  // 	for(auto z:x){cout<<z<<" .";
  // 	}
  // cout<<"\n";
  // 	for(auto z:curr){
  // 		for(auto zz:z)cout<<zz<<" ,";
  // 			cout<<"\n";
  // 	}
  // 	cout<<"\n";
  // 	for(auto z:fin){
  // 		for(auto zz:z)cout<<zz<<" /";
  // 			cout<<"\n";
  // 	}
  // 	cout<<"\n";
  // return;
  // return;
  while (curr.size() >= 4) {
    int sz = curr.size();
    auto l = curr[sz - 1], s = curr[sz - 2];
    q[l[0]] = s[0];
    q[s[0]] = l[0];
    q[l[1]] = s[1];
    q[s[1]] = l[1];
    curr.pop_back();
    curr.pop_back();
  }
  if (curr.size() == 3) {
    int sz = curr.size();
    auto l = curr[sz - 1], s = curr[sz - 2], t = curr[sz - 3];
    q[l[0]] = s[0];
    q[l[1]] = t[1];
    q[s[0]] = t[0];
    q[s[1]] = l[1];
    q[t[0]] = l[0];
    q[t[1]] = s[1];
    // for(auto z:q)cout<<z<<" ";
    curr.clear();
  }
  // cout<<curr.size()<<"\n";
  if (curr.size() == 2) {
    int sz = curr.size();
    auto l = curr[sz - 1], s = curr[sz - 2];
    // cout<<l[0]<<" "<<l[1]<<" "
    q[l[0]] = s[0];
    q[s[0]] = l[0];
    q[l[1]] = s[1];
    q[s[1]] = l[1];
    curr.clear();
  }
  if (x.size() > 1) {

    int sz = x.size();
    for (int i = 0; i < sz; i++) {
      q[x[i]] = x[(i + 1) % sz];
    }
    if (curr.size() == 1 && x.size() > 1) {
      // cout<<"heefjdf";
      // for(auto z:q)cout<<z<<" ";
      // for(auto z:curr[0])cout<<z<<"\n";
      set<int> stt;
      for (int i = 1; i <= n; i++) {
        if (curr[0].empty())
          break;
        if (q[i] != -1 && !stt.count(i)) {
          auto temp = q[i];
          stt.insert(curr[0].back());
          q[i] = curr[0].back();
          q[curr[0].back()] = temp;
          curr[0].pop_back();
        }
      }
      // for(auto z:q)cout<<z<<" ";
      curr.clear();
    }
    // cout<<"here1"; return;
    x.clear();
  }
  // cout<<"here\n"; ret/urn;
  if (curr.size() == 1) {
    if (fin.empty()) {

      cout << "Impossible\n";
    } else {
      for (auto z : fin) {
        int sz = z.size();
        for (int i = 0; i < sz; i++) {
          q[z[i]] = z[(i - 1 + sz) % sz];
        }
      }
      cout << "Possible\n";
      auto y = curr[0];
      // for(auto z:q)cout<<z<<" "; cout<<"\n";
      set<int> stt;
      for (int i = 1; i <= n; i++) {
        if (y.empty() && x.empty()) {
          break;
        }
        if (q[i] != -1 && !stt.count(i)) {
          auto temp = q[i];
          if (y.empty()) {
            q[i] = x[0];
            stt.insert(x[0]);
            q[x[0]] = temp;
            x.pop_back();
          } else {
            q[i] = y.back();
            stt.insert(y.back());
            q[y.back()] = temp;
            y.pop_back();
          }
        }
      }
      // for(auto z:q)cout<<z<<" "; cout<<"\n";
      vector<int> p(n + 1);
      // for(auto z:q)cout<<z<<" ";
      for (int i = 1; i <= n; i++) {
        p[q[i]] = ai[i];
      }
      for (int i = 1; i <= n; i++)
        cout << p[i] << " ";
      cout << "\n";
      for (int i = 1; i <= n; i++)
        cout << q[i] << " ";
      cout << "\n";
      return;
    }
    return;
  }
  if (n == 1) {
    cout << "Impossible\n";
    return;
  }
  cout << "Possible\n";
  for (auto z : fin) {
    int sz = z.size();
    for (int i = 0; i < sz; i++) {
      q[z[i]] = z[(i - 1 + sz) % sz];
    }
  }
  // for(auto z:q)cout<<z<<" ";
  // cout<<"here"; return;
  if (!x.empty()) {
    for (int i = 1; i <= n; i++) {
      if (q[i] != -1) {
        auto temp = q[i];
        q[i] = x[0];
        q[x[0]] = temp;
        break;
      }
    }
  }
  // for(int i=1;i<=n;i++)cout<<q[i]<<" "; cout<<"\n"; return;
  // cout<<"here"; cout<<"\n"; return;
  vector<int> p(n + 1);
  // for(auto z:q)cout<<z<<" ";/**/ return;
  for (int i = 1; i <= n; i++) {
    p[q[i]] = ai[i];
  }
  for (int i = 1; i <= n; i++)
    cout << p[i] << " ";
  cout << "\n";
  for (int i = 1; i <= n; i++)
    cout << q[i] << " ";
  cout << "\n";
  // for(int i=1;i<=n;i++){
  // 	if(v[p[q[i]]]!=i){
  // 		cout<<i<<"\n"; return;
  // 	}
  // }
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  // cout<<"\nfjsd\n";
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
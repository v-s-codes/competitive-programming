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
const int A = 90;
const int B = 222;
void solve() {
  map<string, int> mp;
  set<string> st;
  for (int i = 0; i < A; i++) {
    string s;
    int b;
    cin >> s >> b;
    s.pop_back();
    st.insert(s);
    mp[s] = b;
  }
  map<string, set<string>> ms;
  map<string, int> indeg;
  map<string, tuple<string, string, string>> m;
  for (int i = 0; i < B; i++) {
    string a, b, c, op, temp;
    cin >> a >> op >> b >> temp >> c;
    st.insert(a);
    st.insert(b);
    st.insert(c);
    ms[a].insert(c);
    ms[b].insert(c);
    m[c] = {a, b, op};
    indeg[c] += 2;
  }
  queue<string> q;
  for (auto i : st) {
    if (indeg[i] == 0) {
      q.push(i);
    }
  }
  while (!q.empty()) {
    string s = q.front();
    if (mp.find(s) == mp.end()) {
      auto x = m[s];
      string a = get<0>(x), b = get<1>(x), op = get<2>(x);
      if (op == "AND") {
        mp[s] = mp[a] & mp[b];
      } else if (op == "OR") {
        mp[s] = mp[a] | mp[b];
      } else if (op == "XOR") {
        mp[s] = mp[a] ^ mp[b];
      }
    }
    q.pop();
    for (auto i : ms[s]) {
      indeg[i]--;
      if (indeg[i] == 0) {
        q.push(i);
      }
    }
  }
  dbg(mp);
  int curr = 1, ans = 0;
  for (auto i : mp) {
    if (i.first[0] == 'z') {
      ans += i.second * curr;
      // multiply curr by 2
      curr <<= 1;
    }
  }
  cout << ans;
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

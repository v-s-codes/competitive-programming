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

#define googleOrFacebook
#define testcases
vector<int> v;
void solve() { dbg("SEX"); }

signed main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  v.clear();
  vector<string> vs;
  for (int i = 0; i < 9; i++) {
    int k = 2 * i + 1;
    vector<string> vx;
    for (int cnt_1 = 0; cnt_1 < k; cnt_1++) {
      for (int cnt_2 = 0; (cnt_2 + cnt_1) < k; cnt_2++) {
        for (int cnt_3 = 0; (cnt_3 + cnt_2 + cnt_1) < k; cnt_3++) {
          for (int cnt_4 = 0; (cnt_4 + cnt_3 + cnt_2 + cnt_1) < k; cnt_4++) {
            for (int cnt_5 = 0; (cnt_5 + cnt_4 + cnt_3 + cnt_2 + cnt_1) < k;
                 cnt_5++) {
              for (int cnt_6 = 0;
                   (cnt_6 + cnt_5 + cnt_4 + cnt_3 + cnt_2 + cnt_1) < k;
                   cnt_6++) {
                for (int cnt_7 = 0; (cnt_7 + cnt_6 + cnt_5 + cnt_4 + cnt_3 +
                                     cnt_2 + cnt_1) < k;
                     cnt_7++) {
                  int cnt_8 = k - (cnt_7 + cnt_6 + cnt_5 + cnt_4 + cnt_3 +
                                   cnt_2 + cnt_1);
                  string s = "";
                  for (int j = 0; j < cnt_1; j++) {
                    s.push_back('0' + 1);
                  }
                  for (int j = 0; j < cnt_2; j++) {
                    s.push_back('0' + 2);
                  }
                  for (int j = 0; j < cnt_3; j++) {
                    s.push_back('0' + 3);
                  }
                  for (int j = 0; j < cnt_4; j++) {
                    s.push_back('0' + 4);
                  }
                  for (int j = 0; j < cnt_5; j++) {
                    s.push_back('0' + 5);
                  }
                  for (int j = 0; j < cnt_6; j++) {
                    s.push_back('0' + 6);
                  }
                  for (int j = 0; j < cnt_7; j++) {
                    s.push_back('0' + 7);
                  }
                  for (int j = 0; j < cnt_8; j++) {
                    s.push_back('0' + 8);
                  }
                  vx.push_back(s);
                }
              }
            }
          }
        }
      }
    }
    dbg(vx.size());
  }
  dbg(vs.size());
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
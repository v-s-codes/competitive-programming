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

// Segment Tree class declaration
class SegmentTree {
private:
  vector<long long> tree, lazy;
  int n;

  void build(int node, int start, int end, const vector<int> &arr) {
    if (start == end) {
      tree[node] = arr[start];
    } else {
      int mid = (start + end) / 2;
      build(2 * node + 1, start, mid, arr);
      build(2 * node + 2, mid + 1, end, arr);
      tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
  }

  void propagate(int node, int start, int end) {
    if (lazy[node] != 0) {
      tree[node] += (end - start + 1) * lazy[node];
      if (start != end) {
        lazy[2 * node + 1] += lazy[node];
        lazy[2 * node + 2] += lazy[node];
      }
      lazy[node] = 0;
    }
  }

  void updateRange(int node, int start, int end, int l, int r, int val) {
    propagate(node, start, end);
    if (start > end || start > r || end < l) {
      return;
    }
    if (start >= l && end <= r) {
      lazy[node] += val;
      propagate(node, start, end);
      return;
    }
    int mid = (start + end) / 2;
    updateRange(2 * node + 1, start, mid, l, r, val);
    updateRange(2 * node + 2, mid + 1, end, l, r, val);
    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
  }

  long long queryRange(int node, int start, int end, int l, int r) {
    propagate(node, start, end);
    if (start > end || start > r || end < l) {
      return 0;
    }
    if (start >= l && end <= r) {
      return tree[node];
    }
    int mid = (start + end) / 2;
    long long leftSum = queryRange(2 * node + 1, start, mid, l, r);
    long long rightSum = queryRange(2 * node + 2, mid + 1, end, l, r);
    return leftSum + rightSum;
  }

public:
  SegmentTree() {}

  SegmentTree(const vector<int> &arr) {
    n = arr.size();
    tree.resize(4 * n, 0);
    lazy.resize(4 * n, 0);
    build(0, 0, n - 1, arr);
  }

  void init(const vector<int> &arr) {
    n = arr.size();
    tree.resize(4 * n, 0);
    lazy.resize(4 * n, 0);
    build(0, 0, n - 1, arr);
  }

  void updateRange(int l, int r, int val) {
    updateRange(0, 0, n - 1, l, r, val);
  }

  long long queryRange(int l, int r) { return queryRange(0, 0, n - 1, l, r); }
};
int n;
// Declare the segment tree globally
SegmentTree segTree;

int minMovesOnRight(int in, int pos) {
  int lo = in, hi = n, mid;
  while (lo < hi) {
    mid = (lo + hi) / 2;
    int mnPos = pos + (mid - in);
    if (mnPos <= segTree.queryRange(mid, mid)) {
      hi = mid;
    } else
      lo = mid + 1;
  }
  int sm = ((lo - in) * (2 * pos + (lo - in - 1))) / 2;
  int ans = sm - (segTree.queryRange(in, lo - 1));

  dbg(pos - segTree.queryRange(in, in), in, lo);
  segTree.updateRange(in, lo, pos - segTree.queryRange(in, in));
  for (int i = 0; i < n; i++)
    dbg(segTree.queryRange(i, i));
  return ans;
}
int minMovesOnLeft(int in, int pos) {
  int lo = -1, hi = in, mid;
  while (lo < hi) {
    mid = (lo + hi + 1) / 2;
    int mnPos = pos - (in - mid);
    if (mnPos >= segTree.queryRange(mid, mid)) {
      lo = mid;
    } else
      hi = mid - 1;
  }
  int sm = ((in - lo) * (2 * pos - (in - lo - 1))) / 2;
  dbg(sm, segTree.queryRange(lo + 1, in));
  int ans = (segTree.queryRange(lo + 1, in)) - sm;
  segTree.updateRange(lo + 1, in, pos - segTree.queryRange(in, in));
  dbg(ans);
  return ans;
}
signed main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  segTree.init(arr);

  int q;
  cin >> q;
  int ans = 0;
  while (q--) {
    int in, pos;
    cin >> in >> pos;
    in--;
    auto qq = segTree.queryRange(in, in);
    if (qq <= pos) {

      ans += minMovesOnRight(in, pos);
    } else
      ans += minMovesOnLeft(in, pos);
  }
  cout << ans;

  return 0;
}

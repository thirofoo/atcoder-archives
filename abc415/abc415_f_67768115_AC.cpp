/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc415/submissions/67768115
 * Submitted at: 2025-07-20 02:56:30
 * Problem URL: https://atcoder.jp/contests/abc415/tasks/abc415_f
 * Result: AC
 * Execution Time: 1385 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll  = long long;
using ull = unsigned long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

using S = ll;
S op(S l, S r) {
  return max(l, r);
}
S e() {
  return 0LL;
}

/* ========== 区間を set で管理する奴 (閉区間) ========== */
/* verify: https://atcoder.jp/contests/abc415/submissions/67768049 */
template<typename T>
class IntervalSet {
  public:
  using Interval                           = pair<long long, long long>;
  inline static const Interval NG_INTERVAL = {-1, -1};

  vector<T>& data;
  set<Interval> intervals;
  ll n;

  IntervalSet(vector<T>& initial_data): data(initial_data) {
    n = data.size();
    if(n == 0) return;
    ll start_idx = 0;
    for(ll i = 1; i < n; i++) {
      if(data[i] != data[start_idx]) {
        intervals.insert({start_idx, i - 1});
        start_idx = i;
      }
    }
    intervals.insert({start_idx, n - 1});
  }

  // i 番目の要素が包含される区間を返す
  Interval find(ll i) const {
    if(i < 0 || i >= n) return NG_INTERVAL;
    auto it = intervals.upper_bound({i, n + 1});
    if(it == intervals.begin()) return NG_INTERVAL;
    it = prev(it);
    if(it->first <= i && i <= it->second) {
      return *it;
    }
    return NG_INTERVAL;
  }

  Interval find_next(ll i) const {
    Interval current_interval = find(i);
    if(current_interval.first == -1) return NG_INTERVAL;
    auto it = intervals.find(current_interval);
    it      = next(it);
    if(it != intervals.end()) {
      return *it;
    }
    return NG_INTERVAL;
  }

  Interval find_prev(ll i) const {
    Interval current_interval = find(i);
    if(current_interval.first == -1) return NG_INTERVAL;
    auto it = intervals.find(current_interval);
    if(it != intervals.begin()) {
      it = prev(it);
      return *it;
    }
    return NG_INTERVAL;
  }

  pair<vector<Interval>, vector<Interval>> update(ll i, const T& value) {
    if(i < 0 || i >= n || data[i] == value) {
      return {{}, {}};
    }

    vector<Interval> deleted_intervals;
    vector<Interval> created_intervals;

    Interval orig_interval = find(i);
    Interval prev_neighbor = find_prev(i);
    Interval next_neighbor = find_next(i);

    data[i]           = value;
    bool merged_left  = (i > 0 && data[i - 1] == data[i]);
    bool merged_right = (i < n - 1 && data[i + 1] == data[i]);

    // 「削除される」区間のリストアップ
    deleted_intervals.emplace_back(orig_interval);
    if(merged_left && prev_neighbor.first != -1) deleted_intervals.emplace_back(prev_neighbor);
    if(merged_right && next_neighbor.first != -1) deleted_intervals.emplace_back(next_neighbor);

    // 「新たに生成される」区間のリストアップ
    auto [orig_l, orig_r] = orig_interval;
    if(orig_l <= i - 1 && !merged_left) created_intervals.emplace_back(Interval{orig_l, i - 1});
    if(i + 1 <= orig_r && !merged_right) created_intervals.emplace_back(Interval{i + 1, orig_r});

    Interval center_interval = {i, i};
    if(merged_left) center_interval.first = (prev_neighbor.first != -1) ? prev_neighbor.first : orig_l;
    if(merged_right) center_interval.second = (next_neighbor.first != -1) ? next_neighbor.second : orig_r;
    created_intervals.emplace_back(center_interval);

    // 差分を実際のsetに適用する
    for(const auto& interval: deleted_intervals) intervals.erase(interval);
    for(const auto& interval: created_intervals) intervals.insert(interval);
    return {deleted_intervals, created_intervals};
  }

  // debug 用の cerr 関数
  const void debug() const {
    cerr << "Intervals: ";
    for(const auto& interval: intervals) {
      cerr << "[" << interval.first << "," << interval.second << "] ";
    }
    cerr << endl;
  }
};

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  segtree<S, op, e> sg_l(n), sg_r(n);

  vector<char> a(n);
  rep(i, n) a[i] = s[i];
  IntervalSet<char> interval_set(a);
  for(auto& interval: interval_set.intervals) {
    auto [l, r] = interval;
    sg_l.set(l, r - l + 1);
    sg_r.set(r, r - l + 1);
  }

  while(q--) {
    ll t;
    cin >> t;
    if(t == 1) {
      ll i;
      char x;
      cin >> i >> x;
      i--;
      auto [deleted_intervals, created_intervals] = interval_set.update(i, x);
      for(const auto& interval: deleted_intervals) {
        auto [l, r] = interval;
        sg_l.set(l, 0);
        sg_r.set(r, 0);
      }
      for(const auto& interval: created_intervals) {
        auto [l, r] = interval;
        sg_l.set(l, r - l + 1);
        sg_r.set(r, r - l + 1);
      }
    } else {
      ll l, r;
      cin >> l >> r;
      l--, r--;
      ll ans = 0;

      // 左端を含む区間
      auto [tl1, tr1] = interval_set.find(l);
      ans             = max(ans, min(tr1, r) - l + 1);

      // 右端を含む区間
      auto [tl2, tr2] = interval_set.find(r);
      ans             = max(ans, r - max(tl2, l) + 1);

      // それ以外の区間の探索
      auto [tl3, tr3] = interval_set.find_next(l);
      if(tl3 != -1 && tl3 <= r + 1) ans = max(ans, sg_r.prod(tl3, r + 1));
      if(tl2 != -1 && l <= tl2) ans = max(ans, sg_l.prod(l, tl2));

      cout << ans << endl;
    }
  }

  return 0;
}

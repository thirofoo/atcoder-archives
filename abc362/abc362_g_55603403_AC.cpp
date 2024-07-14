/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc362/submissions/55603403
 * Submitted at: 2024-07-14 16:37:39
 * Problem URL: https://atcoder.jp/contests/abc362/tasks/abc362_g
 * Result: AC
 * Execution Time: 947 ms
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

/* Suffix Array ( doubling 軸で O( N(logN)^2) ) */
vector<int> constract_SA(const string& s) {
  int n = s.size();
  vector<int> sa(n), rank(n), next;
	for(int i = 0; i < n; i++) {
   sa[i] = i, rank[i] = s[i];
	}

  for(int k = 1; k < n; k *= 2) {
    auto compare = [&](int i, int j) {
      // ダブリングの要領で比較
      if(rank[i] != rank[j]) return rank[i] < rank[j];
      int ri = i + k < n ? rank[i + k] : -1;
      int rj = j + k < n ? rank[j + k] : -1;
      return ri < rj;
    };

    sort(sa.begin(), sa.end(), compare);
    next.assign(n, 0);
    next[sa[0]] = 0;
    for(int i = 1; i < n; i++) {
      // 1 個前と同じなら rank も同じ、違うなら rank をインクリメント
      next[sa[i]] = next[sa[i - 1]] + compare(sa[i - 1], sa[i]);
    }
    swap(rank, next);
  }
  return sa;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string s;
  cin >> s;
  ll q;
  cin >> q;
  vector<int> sa = constract_SA(s);

  auto check = [&](ll idx, const string& t) {
    // s は t より小さいかの比較
    for(ll i = 0; i < t.size(); i++) {
      if(sa[idx] + i >= s.size()) return true;
      if(s[sa[idx] + i] != t[i]) return s[sa[idx] + i] < t[i];
    }
    return false;
  };

  while(q--) {
    string t;
    cin >> t;
    // t と t + "~" で Suffix Array 上で二分探索することで
    // t が含まれる部分文字列の個数が算出可能
    ll l1 = -1, r1 = s.size();
    while(r1 - l1 > 1) {
      ll m1 = (l1 + r1) / 2;
      if(check(m1, t)) l1 = m1;
      else r1 = m1;
    }
    t += "~";
    ll l2 = -1, r2 = s.size();
    while(r2 - l2 > 1) {
      ll m2 = (l2 + r2) / 2;
      if(check(m2, t)) l2 = m2;
      else r2 = m2;
    }
    cout << r2 - r1 << endl;
  }

  return 0;
}
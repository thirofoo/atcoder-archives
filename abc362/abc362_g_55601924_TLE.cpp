/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc362/submissions/55601924
 * Submitted at: 2024-07-14 15:50:57
 * Problem URL: https://atcoder.jp/contests/abc362/tasks/abc362_g
 * Result: TLE
 * Execution Time: 3311 ms
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

/* Suffix Array */
vector<ll> constract_SA(const string &s) {
  ll n = s.size();
  vector<ll> sa(n), rank(n), next;
  rep(i, n) sa[i] = i, rank[i] = s[i];

  for(ll k = 1; k < n; k *= 2) {
    auto compare = [&](ll i, ll j) {
      // ダブリングの要領で比較
      if(rank[i] != rank[j]) return rank[i] < rank[j];
      ll ri = i + k < n ? rank[i + k] : -1;
      ll rj = j + k < n ? rank[j + k] : -1;
      return ri < rj;
    };

    sort(sa.begin(), sa.end(), compare);
    next.assign(n, 0);
    next[sa[0]] = 0;
    for(ll i = 1; i < n; i++) {
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
  vector<int> sa = suffix_array(s);

  auto check = [&](ll idx, string &t) {
    return (s.substr(sa[idx], min(sa[idx] + t.size(), s.size())) < t);
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
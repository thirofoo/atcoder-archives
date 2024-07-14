/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc362/submissions/55604850
 * Submitted at: 2024-07-14 17:25:07
 * Problem URL: https://atcoder.jp/contests/abc362/tasks/abc362_g
 * Result: AC
 * Execution Time: 1120 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)

vector<int> constract_sa(const string& s) {
  int n = s.size();
  vector<int> sa(n), rank(n), next;
  for(int i = 0; i < n; i++) {
    sa[i] = i, rank[i] = s[i];
  }

  for(int k = 1; k < n; k *= 2) {
    auto compare = [&](int i, int j) {
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
  string s;
  ll q;
  cin >> s >> q;
  vector<int> sa = constract_sa(s);

  auto check = [&](ll idx, string& t) {
    // s の idx 番目の suffix と t を比較
    return s.compare(sa[idx], min(s.size() - sa[idx], t.size()), t) < 0;
  };

  while(q--) {
    string t;
		cin >> t;
    // t と t + "~" で Suffix Array 上で二分探索することで
    // t を prefix とする suffix の個数が求まる
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
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc365/submissions/56326542
 * Submitted at: 2024-08-04 11:48:51
 * Problem URL: https://atcoder.jp/contests/abc365/tasks/abc365_g
 * Result: AC
 * Execution Time: 1267 ms
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  // 解説 AC : 平方分割
  // 出入りが多い人のペアは計算量が大きいのでクエリ毎に答えると重い
  // ⇒ D 回以上の人がいるペアは前計算、それ以外はクエリ毎に答える

  // D 回以上の人がいるペアの前計算 : O(M/D * M)
  // それ以外のペア : O(D * Q)
  // D = sqrt(M^2/Q) として平方分割すると解ける

  int n, m;
  cin >> n >> m;
  vector<int> t(m, 0), p(m), pre(n, -1);
  vector<vector<pair<int, int>>> exist(n);
  for(int i = 0; i < m; i++) {
    cin >> t[i] >> p[i];
    p[i]--;
    if(pre[p[i]] == -1) pre[p[i]] = i;
    else {
      exist[p[i]].emplace_back(pre[p[i]], i);
      pre[p[i]] = -1;
    }
  }

  int q;
  cin >> q;
  int threshold = sqrt(m);
  // cerr << "threshold: " << threshold << endl;
  vector<int> frequent_idx, rev_idx(n, -1);
  for(int i = 0; i < n; i++) {
    if(exist[i].size() >= threshold) {
      rev_idx[i] = frequent_idx.size();
      frequent_idx.emplace_back(i);
    }
  }

  vector<int> r;
  vector ans(frequent_idx.size(), vector<int>(m, 0));
  for(int i = 0; i < frequent_idx.size(); i++) {
    // cerr << "frequent_idx: " << frequent_idx[i] << endl;
    // idx 番目の高橋の入室時間の累積和を管理
    r.assign(m, 0);
    for(auto &[left, right]: exist[frequent_idx[i]]) {
      for(int j = left + 1; j <= right; j++) r[j] += t[j] - t[j - 1];
    }
    for(int j = 1; j < m; j++) r[j] += r[j - 1];
    // r を用いて他全員とのペアの合計時間を前計算
    for(int j = 0; j < n; j++) {
      if(j == frequent_idx[i]) continue;
      for(auto &[left, right]: exist[j]) {
        ans[i][j] += r[right] - r[left];
      }
    }
  }

  while(q--) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if(exist[a].size() < exist[b].size()) swap(a, b);
    if(exist[a].size() >= threshold) {
      cout << ans[rev_idx[a]][b] << endl;
    } else {
      // 区間個数が少ない同士のペアは逐次処理
      int res   = 0;
      int a_now = 0, b_now = 0;
      while(a_now < exist[a].size() && b_now < exist[b].size()) {
        auto &[a_left, a_right] = exist[a][a_now];
        auto &[b_left, b_right] = exist[b][b_now];
        if(a_right <= b_left) a_now++;
        else if(b_right <= a_left) b_now++;
        else {
          int left  = max(a_left, b_left);
          int right = min(a_right, b_right);
          // cerr << "left: " << left << " right: " << right << endl;
          res += t[right] - t[left];
          if(a_right < b_right) a_now++;
          else b_now++;
        }
      }
      cout << res << endl;
    }
  }

  return 0;
}
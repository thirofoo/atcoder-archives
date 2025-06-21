/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc411/submissions/66987493
 * Submitted at: 2025-06-22 03:05:05
 * Problem URL: https://atcoder.jp/contests/abc411/tasks/abc411_f
 * Result: AC
 * Execution Time: 626 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;
  cin >> n >> m;

  // 元の辺リスト
  vector<pair<int, int>> edges(m);
  // 縮約後も更新する成分間グラフ
  vector<unordered_set<int>> g(n);

  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    edges[i] = {u, v};
    g[u].insert(v);
    g[v].insert(u);
  }

  int q;
  cin >> q;
  dsu uf(n);
  ll ans = m;

  while(q--) {
    int xi;
    cin >> xi;
    --xi;
    auto [u, v] = edges[xi];

    // 今の代表元を取る
    int ru = uf.leader(u);
    int rv = uf.leader(v);

    // 既に同じ成分か、隣接していないならスキップ
    if(ru == rv || !g[ru].count(rv)) {
      cout << ans << "\n";
      continue;
    }

    // small-to-large: ru 側の集合を大きいほうに揃える
    if(g[ru].size() < g[rv].size()) {
      swap(ru, rv);
    }

    // 実際にマージして、新しい root を得る
    int new_root = uf.merge(ru, rv);
    int old_root = (new_root == ru ? rv : ru);

    // 縮約した辺 1 本を消す
    ans--;

    // old_root の隣接先をすべて走査して new_root に吸収 or 重複削除
    for(int to: g[old_root]) {
      // まず古い参照を消す
      g[to].erase(old_root);

      if(g[new_root].count(to)) {
        // 重複辺なので消す
        ans--;
      } else if(to != new_root) {
        // 新しい辺を張る
        g[new_root].insert(to);
        g[to].insert(new_root);
      }
    }

    // old_root のリストはもう不要
    g[old_root].clear();

    cout << ans << "\n";
  }

  return 0;
}

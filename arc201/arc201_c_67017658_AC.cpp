/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc201/submissions/67017658
 * Submitted at: 2025-06-23 13:11:15
 * Problem URL: https://atcoder.jp/contests/arc201/tasks/arc201_c
 * Result: AC
 * Execution Time: 62 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
using ll  = long long;
using ull = unsigned long long;
using P   = pair<ll, ll>;
using T   = tuple<ll, ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

// ==================== Trie ====================
/* verify: https://atcoder.jp/contests/abc403/submissions/65298165 */
template<size_t AlphabetSize, char MinChar = 'a'>
struct Trie {
  struct Node {
    array<int, AlphabetSize> next;
    ll cnt  = 0; // 末端に達した単語数
    ll pass = 0; // このノードを通過した単語数
    Node() {
      next.fill(-1);
    }
  };

  vector<Node> nodes;
  vector<mint> dp;
  Trie() {
    nodes.emplace_back();
    dp.assign(5e5 + 5, 0);
    return;
  }

  // 挿入
  mint insert(const string& s) {
    ll u = 0;
    nodes[u].pass++;
    vector<ll> path;
    for(char ch: s) {
      ll c = ch - MinChar;
      if(c < 0 || c >= (ll) AlphabetSize) assert(false);
      if(nodes[u].next[c] < 0) {
        nodes[u].next[c] = nodes.size();
        nodes.emplace_back();
      }
      u = nodes[u].next[c];
      path.emplace_back(u);
      nodes[u].pass++;
    }
    nodes[u].cnt++;
    reverse(path.begin(), path.end());
    rep(i, path.size()) {
      ll v       = path[i];
      ll child_a = nodes[v].next[0];
      ll child_b = nodes[v].next[1];
      dp[v]      = 0;
      if(child_a >= 0 && child_b >= 0) dp[v] += dp[child_a] * dp[child_b];
      if(nodes[v].cnt > 0) dp[v] += mint(2).pow(nodes[v].pass - 1);
    }
    return (nodes[0].next[0] < 0 || nodes[0].next[1] < 0) ? mint(0) : dp[nodes[0].next[0]] * dp[nodes[0].next[1]];
  }
};

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  Trie<2, 'A'> trie;
  rep(i, n) {
    string s;
    cin >> s;
    cout << trie.insert(s).val() << endl;
  }

  return 0;
}

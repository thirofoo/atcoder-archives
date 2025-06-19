/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc403/submissions/66880196
 * Submitted at: 2025-06-19 16:48:21
 * Problem URL: https://atcoder.jp/contests/abc403/tasks/abc403_e
 * Result: AC
 * Execution Time: 222 ms
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
  Trie() {
    nodes.emplace_back();
  }

  // 挿入
  void insert(const string& s) {
    ll u = 0;
    nodes[u].pass++;
    for(char ch: s) {
      ll c = ch - MinChar;
      if(c < 0 || c >= (ll) AlphabetSize) return;
      if(nodes[u].next[c] < 0) {
        nodes[u].next[c] = nodes.size();
        nodes.emplace_back();
      }
      u = nodes[u].next[c];
      nodes[u].pass++;
    }
    nodes[u].cnt++;
  }

  // s と完全一致する単語数 (prefix=false)、
  // s を prefix にもつ単語数 (prefix=true)
  ll search(const string& s, bool prefix = false) {
    ll u = 0;
    for(char ch: s) {
      ll c = ch - MinChar;
      if(c < 0 || c >= (ll) AlphabetSize) return 0;
      u = nodes[u].next[c];
      if(u < 0) return 0;
    }
    ll res = nodes[u].pass;
    nodes[u].next.fill(-1);
    u = 0;
    nodes[u].pass -= res;
    for(char ch: s) {
      ll c = ch - MinChar;
      if(c < 0 || c >= (ll) AlphabetSize) return 0;
      u = nodes[u].next[c];
      if(u < 0) return 0;
      nodes[u].pass -= res;
    }
    return res;
  }

  // s と完全一致する文字列の個数
  inline ll count_equal(const string& s) const {
    return search(s, false);
  }

  // s を prefix として持つ文字列の個数
  inline ll count_with_prefix(const string& s) const {
    return search(s, true);
  }

  // s の中に完全に含まれる（挿入済みの文字列が s の prefix となる）文字列の個数
  inline ll count_prefix_of(const string& s) const {
    int u  = 0;
    ll ans = 0;
    for(char ch: s) {
      int c = ch - MinChar;
      if(c < 0 || c >= (int) AlphabetSize) break;
      u = nodes[u].next[c];
      if(u < 0) break;
      ans += nodes[u].cnt;
    }
    return ans;
  }
};

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll q;
  cin >> q;
  Trie<26, 'a'> trieX, trieY;
  ll ans = 0;
  while(q--) {
    ll t;
    string s;
    cin >> t >> s;
    if(t == 1) {
      trieX.insert(s);
      ans -= trieY.search(s);
    } else {
      if(trieX.count_prefix_of(s) == 0) {
        trieY.insert(s);
        ans++;
      }
    }
    cout << ans << endl;
  }

  return 0;
}
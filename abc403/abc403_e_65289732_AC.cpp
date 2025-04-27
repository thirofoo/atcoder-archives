/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc403/submissions/65289732
 * Submitted at: 2025-04-27 22:39:22
 * Problem URL: https://atcoder.jp/contests/abc403/tasks/abc403_e
 * Result: AC
 * Execution Time: 52 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll  = long long;
using ull = unsigned long long;
using P   = pair<ll, ll>;
using T   = tuple<ll, ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

struct node {
  array<ll, 26> children;
  ll count_y               = 0;
  bool covered_by_x_prefix = false;
  node() {
    children.fill(-1);
  }
};

class trie {
  vector<node> nodes;
  ll total_y     = 0;
  ll forbidden_y = 0;

  ll create_node() {
    nodes.emplace_back();
    return (ll) nodes.size() - 1;
  }

  ll propagate_coverage(ll u) {
    if(u < 0 || nodes[u].covered_by_x_prefix) return 0;
    nodes[u].covered_by_x_prefix = true;
    ll c                         = nodes[u].count_y;
    for(int i = 0; i < 26; ++i) {
      c += propagate_coverage(nodes[u].children[i]);
    }
    return c;
  }

  public:
  trie() {
    nodes.reserve(500001);
    nodes.emplace_back();
  }

  void add_x(const string& s) {
    ll u              = 0;
    bool path_covered = false;
    for(char ch: s) {
      if(nodes[u].covered_by_x_prefix) {
        path_covered = true;
        break;
      }
      int ci = ch - 'a';
      if(nodes[u].children[ci] < 0) break;
      u = nodes[u].children[ci];
    }
    if(!path_covered && nodes[u].covered_by_x_prefix) {
      path_covered = true;
    }
    ll v = 0;
    for(char ch: s) {
      int ci = ch - 'a';
      if(nodes[v].children[ci] < 0) {
        nodes[v].children[ci] = create_node();
      }
      v = nodes[v].children[ci];
    }
    if(!path_covered) {
      forbidden_y += propagate_coverage(v);
    }
    nodes[v].covered_by_x_prefix = true;
  }

  void add_y(const string& s) {
    ll u              = 0;
    bool is_forbidden = false;
    for(char ch: s) {
      if(nodes[u].covered_by_x_prefix) {
        is_forbidden = true;
      }
      int ci = ch - 'a';
      if(nodes[u].children[ci] < 0) {
        nodes[u].children[ci] = create_node();
      }
      u = nodes[u].children[ci];
    }
    if(nodes[u].covered_by_x_prefix) {
      is_forbidden = true;
    }
    nodes[u].count_y++;
    total_y++;
    if(is_forbidden) {
      forbidden_y++;
    }
  }

  ll get_allowed_y() const {
    return total_y - forbidden_y;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  trie tr;
  ll q;
  cin >> q;
  while(q--) {
    int tp;
    string s;
    cin >> tp >> s;
    if(tp == 1) tr.add_x(s);
    else tr.add_y(s);
    cout << tr.get_allowed_y() << "\n";
  }

  return 0;
}

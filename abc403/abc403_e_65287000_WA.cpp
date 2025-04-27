/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc403/submissions/65287000
 * Submitted at: 2025-04-27 22:33:19
 * Problem URL: https://atcoder.jp/contests/abc403/tasks/abc403_e
 * Result: WA
 * Execution Time: 51 ms
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
  ll ch[26];
  ll cnt_y        = 0;
  bool cov_x_pref = false;
  node() {fill(ch, ch + 26, -1);}
};

class trie {
  vector<node> nd;
  ll tot_y  = 0;
  ll forb_y = 0;

  ll new_node() {
    nd.emplace_back();
    return (ll) nd.size() - 1;
  }

  ll propagate_cov(ll u) {
    if(u < 0 || nd[u].cov_x_pref) return 0;
    nd[u].cov_x_pref = true;
    ll c             = nd[u].cnt_y;
    for(ll i = 0; i < 26; ++i) c += propagate_cov(nd[u].ch[i]);
    return c;
  }

  public:
  trie() {
    nd.reserve(500001);
    nd.emplace_back();
  }

  void add_x(string &s) {
    ll u = 0;
    for(char x: s) {
      ll &v = nd[u].ch[x - 'a'];
      if(v == -1) v = new_node();
      u = v;
    }
    forb_y += propagate_cov(u);
  }

  void add_y(string &s) {
    bool forb = false;
    ll u      = 0;
    for(char x: s) {
      if(nd[u].cov_x_pref) forb = true;
      ll &v = nd[u].ch[x - 'a'];
      if(v == -1) v = new_node();
      u = v;
    }
    if(nd[u].cov_x_pref) forb = true;
    nd[u].cnt_y++;
    tot_y++;
    if(forb) forb_y++;
  }

  ll get_allowed_y() {return tot_y - forb_y;}
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // Trie 木を少し改造すればいけそう？

  trie tr;
  ll n;
  cin >> n;
  while(n--) {
    ll tp;
    string s;
    cin >> tp >> s;
    if(tp == 1) tr.add_x(s);
    else tr.add_y(s);
    cout << tr.get_allowed_y() << '\n';
  }
  return 0;
}

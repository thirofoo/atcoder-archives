/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc353/submissions/53399142
 * Submitted at: 2024-05-12 12:06:53
 * Problem URL: https://atcoder.jp/contests/abc353/tasks/abc353_e
 * Result: AC
 * Execution Time: 38 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)
const ll INF = ((1LL << 62)-(1LL << 31));

struct Node {
    char c; // Node の文字
    ll cnt; // 該当文字列の個数
    ll depth; // Node の深さ
    map<char, Node*> children;
};

struct Trie {
    Node* root;
    Trie() : root(new Node()) {}

    ll insert(const string &s) {
        ll res = 0; // ABC353-E 用に追加
        Node* node = root;
        for(char c : s) {
            if( node->children.count(c) == 0 ) {
                node->children[c] = new Node();
            }
            node = node->children[c];
            res += node->cnt; // ABC353-E 用に追加
            node->cnt++;
        }
        return res; // ABC353-E 用に追加
    }

    ll search(const string &s) {
        // return : 文字列 s を prefix として持つ文字列の個数
        Node* node = root;
        for(char c : s) {
            if( node->children.count(c) == 0 ) return 0;
            node = node->children[c];
        }
        return node->cnt;
    }
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    Trie trie;
    ll ans = 0;
    rep(i,n) {
        string s; cin >> s;
        ans += trie.insert(s);
    }
    cout << ans << '\n';
    
    return 0;
}
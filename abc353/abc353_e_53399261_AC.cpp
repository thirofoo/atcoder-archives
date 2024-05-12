/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc353/submissions/53399261
 * Submitted at: 2024-05-12 12:11:26
 * Problem URL: https://atcoder.jp/contests/abc353/tasks/abc353_e
 * Result: AC
 * Execution Time: 36 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)

struct Node {
    char c; // Node の文字
    ll cnt; // 該当文字列の個数
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
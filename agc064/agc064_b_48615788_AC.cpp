/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc064/submissions/48615788
 * Submitted at: 2023-12-17 19:53:02
 * Problem URL: https://atcoder.jp/contests/agc064/tasks/agc064_b
 * Result: AC
 * Execution Time: 573 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, char, ll>;
using T2 = tuple<ll, ll, char, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;
    vector Graph(n,vector<T>{});
    rep(i,m) {
        ll a, b; char c; cin >> a >> b >> c; a--; b--;
        Graph[a].emplace_back(T(b,c,i));
        Graph[b].emplace_back(T(a,c,i));
    }
    string s; cin >> s;
    vector<T2> edge;
    set<ll> ans, v;
    dsu uf(n);
    rep(a,n) {
        for(auto &&[b,c,idx]:Graph[a]) {
            if( s[a] == c && s[b] == c && !uf.same(a,b) ) {
                ans.insert(idx);
                v.insert(a);
                v.insert(b);
                uf.merge(a,b);
            }
            else if( s[a] == c ) edge.emplace_back(T2(a,b,c,idx));
            else if( s[b] == c ) edge.emplace_back(T2(b,a,c,idx));
        }
    }
    queue<T2> todo;
    for(auto &&[a,b,c,i]:edge) {
        if( !v.count(a) && v.count(b) ) todo.push(T2(a,b,c,i));
    }
    while( !todo.empty() ) {
        auto [a,b,c,i] = todo.front(); todo.pop();
        if( v.count(a) || uf.same(a,b) ) continue;
        v.insert(a);
        ans.insert(i);
        uf.merge(a,b);
        for(auto [to,nc,ni]:Graph[a]) {
            if( v.count(to) || uf.same(a,to) || s[to] != nc ) continue;
            todo.push(T2(to,a,nc,ni));
        }
    }
    if( v.size() != n ) return cout << "No" << endl, 0;
    rep(a,n) {
        for(auto &&[b,c,idx]:Graph[a]) {
            if( ans.count(idx) ) continue;
            if( !uf.same(a,b) ) {
                ans.insert(idx);
                uf.merge(a,b);
            }
        }
    }
    if( uf.size(0) != n ) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        for(auto ele:ans) cout << ele+1 << " ";
        cout << endl;
    }
    
    return 0;
}
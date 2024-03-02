/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc343/submissions/50776532
 * Submitted at: 2024-03-02 21:03:57
 * Problem URL: https://atcoder.jp/contests/abc343/tasks/abc343_b
 * Result: AC
 * Execution Time: 2 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<vector<ll>> Graph(n);
    rep(i,n) rep(j,n) {
        ll a; cin >> a;
        if( a ) {
            Graph[i].push_back(j);
            Graph[j].push_back(i);
        }
    }
    rep(i,n) {
        sort(Graph[i].begin(), Graph[i].end());
        Graph[i].erase(unique(Graph[i].begin(), Graph[i].end()), Graph[i].end());
    }
    rep(i,n) {
        for(auto ele: Graph[i]) cout << ele+1 << " ";
        cout << endl;
    }
    
    return 0;
}
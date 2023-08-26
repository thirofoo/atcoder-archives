/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc317/submissions/44949364
 * Submitted at: 2023-08-26 21:11:01
 * Problem URL: https://atcoder.jp/contests/abc317/tasks/abc317_c
 * Result: AC
 * Execution Time: 32 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m; cin >> n >> m;
    vector<vector<ll>> Graph(n,vector<ll>(n,-1));
    rep(i,m) {
        ll a,b,c; cin >> a >> b >> c;
        a--; b--;
        Graph[a][b] = c;
        Graph[b][a] = c;
    }
    vector<ll> p(n);
    iota(p.begin(), p.end(), 0);
    ll ans = 0;
    do {
        ll cand = 0, cnt = 0;
        bool f = true;
        rep(i,n-1) {
            if( Graph[p[i]][p[i+1]] == -1 && cnt ) break;
            if( Graph[p[i]][p[i+1]] == -1 ) continue;
            if( f ) {
                cand += Graph[p[i]][p[i+1]];
                cnt++;
            }
        }
        ans = max(ans,cand);
    }while(next_permutation(p.begin(), p.end()));
    cout << ans << endl;
    
    return 0;
}
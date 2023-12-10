/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc332/submissions/48388487
 * Submitted at: 2023-12-10 21:43:34
 * Problem URL: https://atcoder.jp/contests/abc332/tasks/abc332_d
 * Result: AC
 * Execution Time: 3 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h, w; cin >> h >> w;
    vector<vector<ll>> a(h,vector<ll>(w)), b(h,vector<ll>(w));
    rep(i,h) rep(j,w) cin >> a[i][j];
    rep(i,h) rep(j,w) cin >> b[i][j];
    vector<ll> p1(h,0), p2(w,0);
    iota(p1.begin(), p1.end(), 0);
    iota(p2.begin(), p2.end(), 0);
    ll ans = 1e9;
    do {
        do {
            bool f = true;
            rep(i,h) rep(j,w) f &= (a[i][j] == b[p1[i]][p2[j]]);
            if( f ) {
                ll cand = 0;
                fenwick_tree<ll> fw1(10), fw2(10);
                rep(i,h) {
                    cand += fw1.sum(p1[i]+1,10);
                    fw1.add(p1[i],1);
                }
                rep(i,w) {
                    cand += fw2.sum(p2[i]+1,10);
                    fw2.add(p2[i],1);
                }
                ans = min(ans,cand);
            }
        } while(next_permutation(p2.begin(),p2.end()));    
    } while(next_permutation(p1.begin(),p1.end()));
    cout << (ans == 1e9 ? -1 : ans) << endl;
    
    return 0;
}
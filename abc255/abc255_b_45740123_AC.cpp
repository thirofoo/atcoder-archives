/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc255/submissions/45740123
 * Submitted at: 2023-09-20 09:33:48
 * Problem URL: https://atcoder.jp/contests/abc255/tasks/abc255_b
 * Result: AC
 * Execution Time: 557 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ld, ld>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    
    ll n, k; cin >> n >> k;
    vector<ld> a(k);
    vector<P> p;
    rep(i,k) cin >> a[i];
    rep(i,n) {
        ld x, y; cin >> x >> y;
        p.emplace_back(P(x,y));
    }
    ld left = 0, right = 1e13;
    while( right-left > 0.0000001 ) {
        ld mid = (right+left)/2;
        set<ll> st;
        rep(i,k) {
            auto &&[x,y] = p[a[i]-1];
            st.insert(a[i]-1);
            rep(j,n) {
                auto &&[tx,ty] = p[j];
                ld dis = (x-tx)*(x-tx) + (y-ty)*(y-ty);
                if( dis <= mid*mid ) st.insert(j);
            }
        }
        if( st.size() == n ) right = mid;
        else left = mid;
    }
    cout << right << endl;
    
    return 0;
}
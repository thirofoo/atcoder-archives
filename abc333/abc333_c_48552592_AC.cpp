/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc333/submissions/48552592
 * Submitted at: 2023-12-16 21:15:45
 * Problem URL: https://atcoder.jp/contests/abc333/tasks/abc333_c
 * Result: AC
 * Execution Time: 1 ms
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
    
    ll n; cin >> n;
    ll cnt = 0;
    vector<vector<ll>> ans;
    for(ll i=0; i<=12; i++) {
        for(ll j=0; j<=12-i; j++) {
            for(ll k=0; k<=12-i-j; k++) {
                if( 12-i-j-k == 0 ) continue;
                vector<ll> cand;
                rep(m,i) cand.emplace_back(0);
                rep(m,j) cand.emplace_back(1);
                rep(m,k) cand.emplace_back(2);
                rep(m,12-i-j-k) cand.emplace_back(3);
                ans.emplace_back(cand);
            }
        }
    }
    sort(ans.begin(), ans.end());
    for(auto ele:ans[n-1]) {
        if( ele == 0 ) continue;
        cout << ele;
    }
    cout << endl;
    
    return 0;
}
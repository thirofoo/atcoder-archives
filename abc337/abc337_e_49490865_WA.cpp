/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc337/submissions/49490865
 * Submitted at: 2024-01-20 21:59:44
 * Problem URL: https://atcoder.jp/contests/abc337/tasks/abc337_e
 * Result: WA
 * Execution Time: 3 ms
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
    ll tn = n-1, m = 0; 
    while( tn > 0 ) {
        tn /= 2;
        m++;
    }
    cout << m << endl;
    // 答え用意
    vector<ll> mask(m, 0);
    vector<vector<ll>> ans(m);
    rep(i,n) rep(j,m) {
        if( i & (1<<j) ) {
            ans[j].emplace_back(i);
            mask[j] |= (1ll << i);
        }
    }
    rep(i,m) {
        cout << ans[i].size() << " ";
        for(auto ele: ans[i]) cout << ele+1 << " ";
        cout << endl;
    }
    string s; cin >> s;
    // bitset で実装 (初期値 111...)
    bitset<200> flag;
    flag.set();
    rep(i,m) if( s[i] == '1' ) flag &= mask[i];
    rep(i,n) {
        if( flag[i] ) {
            cout << i+1 << endl;
            return 0;
        }
    }
    
    return 0;
}
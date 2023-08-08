/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc304/submissions/44375468
 * Submitted at: 2023-08-08 10:37:20
 * Problem URL: https://atcoder.jp/contests/abc304/tasks/abc304_f
 * Result: AC
 * Execution Time: 359 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
#define rep(i, n) for(ll i = 0; i < n; i++)

inline long long GCD(long long a, long long b){
    // 負 or a == 0 で -1
    if( a <= 0 || b < 0 ) return -1;
    if( b != 0 ) return GCD(b,a%b);
    return a;
}

//約数列挙ver(1,nも含む)
vector<ll> divisor(ll n){
    vector<ll> div;
    for(ll i=1;i*i<=n;i++){
        if(n%i)continue;
        div.push_back(i);
        if(i != n/i && i != 1)div.push_back(n/i);
    }
    sort(div.begin(), div.end());
    return div;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; string s; cin >> n >> s;
    vector<ll> div = divisor(n);

    // それぞれの周期でしか出来なやつを memo → 包除可能になる
    mint ans = 0;
    vector<mint> memo(n+1,0);
    for(auto d:div) {
        vector<ll> n_div = divisor(d);
        set<ll> st;
        rep(i,n) if(s[i] == '.') st.insert(i%d);

        mint cand = mint(2).pow(d-st.size());
        for(auto nd:n_div) cand -= memo[nd];
        memo[d] = cand;
        ans += cand;
    }
    // rep(i,n+1) cout << memo[i].val() << " ";
    // cout << endl;
    cout << ans.val() << endl;
    
    return 0;
}
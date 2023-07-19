/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc105/submissions/43736002
 * Submitted at: 2023-07-19 09:02:27
 * Problem URL: https://atcoder.jp/contests/abc105/tasks/abc105_c
 * Result: AC
 * Execution Time: 37 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, now; cin >> n;
    vector<ll> even, odd;
    rep(i,(1LL << 18)){
        now = 0;
        for(ll j=17;j>=0;j--){
            now *= 4;
            now += ( ( i & (1LL << j) ) > 0 );
        }
        even.push_back(now);
    }
    rep(i,(1LL << 18)){
        now = 0;
        for(ll j=17;j>=0;j--){
            now *= 4;
            now += ( ( i & (1LL << j) ) > 0 );
        }
        now *= 2;
        odd.push_back(now);
    }
    for(auto ele:even){
        if( n-ele > 0 ) continue;
        auto itr = lower_bound( odd.begin(), odd.end(), abs(n-ele) );
        if( *itr == abs(n-ele) ){
            ll ans = ele + *itr;
            string s = "";
            rep(i,36) s += ( (ans & (1LL << i)) ? "1" : "0" );
            while( s.back() == '0' ) s.pop_back();
            reverse( s.begin(), s.end() );
            cout << ( s.empty() ? "0" : s ) << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    
    return 0;
}
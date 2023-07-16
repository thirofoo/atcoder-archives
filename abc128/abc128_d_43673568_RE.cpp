/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc128/submissions/43673568
 * Submitted at: 2023-07-16 22:36:58
 * Problem URL: https://atcoder.jp/contests/abc128/tasks/abc128_d
 * Result: RE
 * Execution Time: 110 ms
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
    
    // 戻す必要があるのは - だけ
    // 左端から何個取り出すべきかを全探索

    ll n,k; cin >> n >> k;
    deque<ll> d(n);
    rep(i,n) cin >> d[i];
    ll ans = 0;
    rep(i,n){
        ll rest_turn = k-(i+1);
        if( rest_turn <= 0 ) continue;
        deque<ll> rest = d, my_d;
        rep(j,i+1) {
            ll left = rest.front(); rest.pop_front();
            if( left >= 0 ) my_d.push_back(left);
            else my_d.push_front(left);
        }
        while( rest_turn-- ){
            if( !my_d.empty() && -my_d.front() >= rest.back() ){
                rest.push_front( my_d.front() );
                my_d.pop_front();
            }
            else{
                my_d.push_back( rest.back() );
                rest.pop_back();
            }
        }
        ll cand = 0;
        for(auto ele:my_d) cand += ele;
        ans = max(ans,cand);
    }
    cout << ans << endl;
    
    return 0;
}
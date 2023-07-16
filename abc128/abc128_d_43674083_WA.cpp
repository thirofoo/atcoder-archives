/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc128/submissions/43674083
 * Submitted at: 2023-07-16 22:59:00
 * Problem URL: https://atcoder.jp/contests/abc128/tasks/abc128_d
 * Result: WA
 * Execution Time: 8 ms
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
    for(ll i=0;i<=n;i++){
        ll rest_turn = k-i;
        if( rest_turn < 0 ) continue;
        deque<ll> rest = d, my_d;
        ll cand = 0;
        rep(j,i) {
            ll left = rest.front(); rest.pop_front();
            if( left >= 0 ) my_d.push_back(left);
            else my_d.push_front(left);
            cand += left;
            ans = max(ans,cand);
        }
        // my_dの左端から何個返すかを全探索
        for(ll j=0;j<=my_d.size();j++) {
            if( j > rest_turn ) continue;
            ll now_rest_turn = rest_turn - j, now_cand = cand;
            deque<ll> tmp_my_d = my_d, tmp_rest = rest;
            rep(k,j) {
                now_cand -= tmp_my_d.front();
                ans = max(ans,now_cand);
                tmp_rest.push_front( tmp_my_d.front() );
                tmp_my_d.pop_front();
            }
            while( now_rest_turn-- ){
                if( tmp_rest.empty() ) break;
                now_cand += tmp_rest.back();
                ans = max(ans,now_cand);
                tmp_my_d.push_back( tmp_rest.back() );
                tmp_rest.pop_back();
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}
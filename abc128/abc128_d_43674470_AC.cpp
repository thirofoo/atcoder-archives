/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc128/submissions/43674470
 * Submitted at: 2023-07-16 23:16:23
 * Problem URL: https://atcoder.jp/contests/abc128/tasks/abc128_d
 * Result: AC
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

    // 誤読 : 取得したものは deque に詰めない → 好きなやつを戻せる
    ll n,k; cin >> n >> k;
    deque<ll> d(n);
    rep(i,n) cin >> d[i];
    ll ans = 0;
    for(ll left=0;left<=n;left++){
        for(ll right=0;right<=n;right++){
            if( left + right > min(n,k) ) continue;
            ll cand = 0;
            vector<ll> has;
            rep(k,left) {
                has.push_back( d[k] );
                cand += d[k];
            }
            rep(k,right) {
                has.push_back( d[n-1-k] );
                cand += d[n-1-k];
            }
            sort( has.begin(), has.end() );

            ll rest_turn = k - (left + right);
            rep(k,has.size()){
                if( rest_turn == 0 || has[k] >= 0 ) break;
                cand -= has[k];
                rest_turn--;
            }
            ans = max(ans,cand);
        }
    }
    cout << ans << endl;
    
    return 0;
}
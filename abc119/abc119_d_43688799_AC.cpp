/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc119/submissions/43688799
 * Submitted at: 2023-07-17 15:31:23
 * Problem URL: https://atcoder.jp/contests/abc119/tasks/abc119_d
 * Result: AC
 * Execution Time: 262 ms
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
    
    ll a,b,q; cin >> a >> b >> q;
    vector<ll> s(a), t(b), x(q);
    rep(i,a) cin >> s[i];
    rep(i,b) cin >> t[i];
    rep(i,q) {
        cin >> x[i];
        // 8通り全探索
        // 1. 初動東西どちらか
        // 2. 神社・寺どちらに先行くか
        // 3. そのあと東西どちらか
        ll ans = 1e16;
        rep(j,2){
            // j == 0 : 神社 , j == 1 : 寺
            rep(k,2){
                // k == 0 : 西 , k == 1 : 東
                ll cand = 0, now = x[i];
                auto itr1 = lower_bound(s.begin(), s.end(), now);
                if( (itr1 == s.end() && k == 1) || (itr1 == s.begin() && k == 0) ) continue;
                if( k == 0 ) itr1--;

                cand += abs(now-(*itr1));
                now = *itr1;

                auto itr2 = lower_bound(t.begin(), t.end(), now);
                ll mini = 1e16;
                if( itr2 != t.end() ) mini = min(mini,abs(now-(*itr2)) );
                if( itr2 != t.begin() ) mini = min(mini,abs(now-(*(--itr2))) );
                cand += mini;
                ans = min(ans,cand);
            }
            swap(s,t);
        }
        cout << ans << endl;
    }
    
    return 0;
}
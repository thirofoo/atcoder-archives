/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc119/submissions/43687380
 * Submitted at: 2023-07-17 14:24:51
 * Problem URL: https://atcoder.jp/contests/abc119/tasks/abc119_d
 * Result: AC
 * Execution Time: 249 ms
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
    vector<ll> s, t, x(q);
    s.push_back(-1e16); s.push_back(-1e16);
    t.push_back(-1e16); t.push_back(-1e16);
    rep(i,a) {
        ll ts; cin >> ts;
        s.push_back(ts);
    }
    rep(i,b) {
        ll tt; cin >> tt;
        t.push_back(tt) ;
    }
    s.push_back(1e16); s.push_back(1e16);
    t.push_back(1e16); t.push_back(1e16);
    rep(i,q) {
        cin >> x[i];
        // 8通り全探索
        // 1. 初動東西どちらか
        // 2. 神社・寺どちらに先行くか
        // 3. そのあと東西どちらか
        ll ans = 1e16;
        rep(j,2){
            // j == 0 : 西 , j == 1 : 東
            rep(k,2){
                // k == 0 : 神社 , k == 1 : 寺
                ll cand = 0, now = x[i];
                auto itr1 = lower_bound(s.begin(), s.end(), now);
                if( j == 0 ) itr1--;

                cand += abs(now-(*itr1));
                now = *itr1;

                auto itr2 = lower_bound(t.begin(), t.end(), now);
                ll mini = 1e16;
                mini = min(mini,abs(now-(*itr2)));
                mini = min(mini,abs(now-(*(--itr2))));
                cand += mini;
                ans = min(ans,cand);

                swap(s,t);
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}
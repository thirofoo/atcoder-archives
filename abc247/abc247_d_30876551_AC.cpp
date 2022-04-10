/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc247/submissions/30876551
 * Submitted at: 2022-04-10 21:49:42
 * Problem URL: https://atcoder.jp/contests/abc247/tasks/abc247_d
 * Result: AC
 * Execution Time: 296 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    ll q; cin >> q;
    deque<P> ball;
    rep(i,q){
        ll t; cin >> t;
        if(t == 1){
            ll x,c; cin >> x >> c;
            ball.push_back(P(x,c));
        }
        else{
            ll c,ans = 0; cin >> c;
            while(true){
                if(ball.empty())break;
                auto [x,num] = ball.front(); ball.pop_front();
                if(num > c){
                    ans += x*c; num -= c;
                    ball.push_front(P(x,num));
                    break;
                }
                else ans += x*num; c -= num;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
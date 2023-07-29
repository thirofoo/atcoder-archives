/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc312/submissions/44088077
 * Submitted at: 2023-07-30 00:39:20
 * Problem URL: https://atcoder.jp/contests/abc312/tasks/abc312_f
 * Result: WA
 * Execution Time: 67 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;
    // can1 : 採用したカン, can2 ; 不採用のカン
    priority_queue<ll,vector<ll>,greater<ll>> can1;
    priority_queue<ll> cankiri, can2;
    ll ans = 0, now = 0;
    rep(i,n) {
        ll t, x; cin >> t >> x;
        if( t == 0 ) {
            now += x;
            can1.push(x);
            if( can1.size() > m ) {
                can1.pop();
                now -= x;
            }
        }
        else if( t == 1 ) can2.push(x);
        else cankiri.push(x);
    }
    ans = now;

    // 採用したカンが M個 に満たない時様に 0 を埋め尽くしておく
    while( can1.size() < m ) can1.push(0);

    while( !cankiri.empty() ) {
        // 缶切りを追加すべく、今採用しているカンのうち一番雑魚を排除
        now -= can1.top(); can1.pop();
        ll cnt = cankiri.top(); cankiri.pop();
        rep(i,cnt) {
            if( can2.empty() ) break;
            now += can2.top();
            can1.push( can2.top() ); can2.pop();
            now -= can1.top();
            can1.pop();
            ans = max(ans, now);
        }
    }
    cout << ans << endl;
    
    return 0;
}
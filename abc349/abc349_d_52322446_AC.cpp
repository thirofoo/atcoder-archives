/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc349/submissions/52322446
 * Submitted at: 2024-04-13 21:27:50
 * Problem URL: https://atcoder.jp/contests/abc349/tasks/abc349_d
 * Result: AC
 * Execution Time: 1 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll l, r; cin >> l >> r;
    // 同じサイズの区間は隣り合わない
    ll now = l;
    vector<P> ans;
    while( now < r ) {
        ll time = 1, cnt = 0, max_cnt = 0, tmp = now;
        if( now != 0 ) {
            while( true ) {
                if( tmp%2 ) break;
                tmp /= 2;
                max_cnt++;
            }
        }
        else max_cnt = 1e6;

        while( cnt < max_cnt ) {
            if( now + time*2 > r ) break;
            time *= 2;
            cnt++;
        }
        ans.emplace_back(P(now, now+time));
        now += time;
    }
    cout << ans.size() << endl;
    for(auto [l, r] : ans) cout << l << " " << r << endl;
    
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc319/submissions/45378066
 * Submitted at: 2023-09-09 21:32:55
 * Problem URL: https://atcoder.jp/contests/abc319/tasks/abc319_d
 * Result: AC
 * Execution Time: 36 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;
    vector<ll> l(n);
    ll max_l = 0;
    rep(i,n) {
        cin >> l[i];
        max_l = max(max_l, l[i]);
    }

    ll left = 0, right = 1e16;
    while( right-left > 1 ) {
        ll mid = (right+left)/2;
        if( mid < max_l ) {
            left = mid;
            continue;
        }

        ll now = 0, gyo = 1;
        rep(i,n) {
            if( now+l[i] <= mid ) {
                now += l[i];
            }
            else {
                gyo++;
                now = l[i];
            }
            now++;
        }
        if( gyo <= m ) right = mid;
        else left = mid;
    }
    cout << right << endl;
    
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc273/submissions/44378399
 * Submitted at: 2023-08-08 12:43:13
 * Problem URL: https://atcoder.jp/contests/abc273/tasks/abc273_e
 * Result: AC
 * Execution Time: 482 ms
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
    
    // 木の上の移動として捉えるっぽい
    ll q; cin >> q;
    map<ll,ll> note;
    vector<ll> ans(q,-1), pre(q,-1);
    ll idx = 0, now = 0;
    while(q--) {
        string s; cin >> s;
        if( s == "ADD" ) {
            ll x; cin >> x;
            idx++;
            pre[idx] = now;
            ans[idx] = x;
            now = idx;
        }
        else if( s == "DELETE" ) {
            if( pre[now] != -1 ) now = pre[now];
        }
        else if( s == "SAVE" ) {
            ll y; cin >> y;
            note[y] = now;
        }
        else {
            ll z; cin >> z;
            now = note[z];
        }
        cout << ans[now] << " ";
    }
    cout << endl;
    
    return 0;
}
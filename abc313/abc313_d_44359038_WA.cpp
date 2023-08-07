/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc313/submissions/44359038
 * Submitted at: 2023-08-07 17:18:33
 * Problem URL: https://atcoder.jp/contests/abc313/tasks/abc313_d
 * Result: WA
 * Execution Time: 141 ms
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
    
    ll n,k; cin >> n >> k;
    vector<ll> res(n);

    if( k == 1 ) {
        rep(i,n) {
            cout << "?";
            rep(i,k) cout << " " << i+1;
            cout << endl << flush;
            cin >> res[i];
        }
        cout << "!";
        rep(i,n) cout << " " << res[i];
        cout << endl << flush;
        return 0;
    }

    rep(i,k-1) {
        cout << "?";
        ll cnt = 0;
        rep(j,n) {
            if( i == j ) continue;
            cout << " " << j+1;
            cnt++;
            if( cnt == k ) break;
        }
        cout << endl << flush;
        cin >> res[i];
    }
    for(ll i=k-1;i<n;i++) {
        cout << "?";
        rep(j,k-1) cout << " " << j+1;
        cout << " " << i+1 << endl << flush;
        cin >> res[i];
    }

    vector<ll> ans(n,0);
    for(ll i=0;i<k-2;i++) ans[i+1] = ans[i] ^ (res[i] != res[i+1]);
    ans[k-1] = ans[k-2] ^ (res[k-2] != res[k]);
    for(ll i=k-1;i<n-1;i++) ans[i+1] = ans[i] ^ (res[i] != res[i+1]);

    ll cnt = 0;
    rep(i,k) cnt += ans[i+1];
    bool f = ((cnt%2 == 0 && res[0] == 1) || (cnt%2 == 1 && res[0] == 0));
    cout << "!";
    rep(i,n) cout << " " << (f ? !ans[i] : ans[i]);
    cout << endl << flush;
    
    return 0;
}
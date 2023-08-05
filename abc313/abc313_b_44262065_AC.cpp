/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc313/submissions/44262065
 * Submitted at: 2023-08-05 21:05:58
 * Problem URL: https://atcoder.jp/contests/abc313/tasks/abc313_b
 * Result: AC
 * Execution Time: 5 ms
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
    
    ll n,m; cin >> n >> m;
    vector<ll> dig(n,0);
    rep(i,m) {
        ll a,b; cin >> a >> b;
        a--; b--;
        dig[b]++;
    }
    ll cnt = 0, ans = -1;
    rep(i,n) {
        if(dig[i] == 0) {
            cnt++;
            ans = i+1;
        }
    }
    cout << (cnt == 1 ? ans : -1) << endl;

    
    return 0;
}
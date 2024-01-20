/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc337/submissions/49451665
 * Submitted at: 2024-01-20 21:11:58
 * Problem URL: https://atcoder.jp/contests/abc337/tasks/abc337_c
 * Result: AC
 * Execution Time: 35 ms
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
    
    ll n; cin >> n;
    vector<ll> a(n), child(n, -1);
    ll now;
    rep(i,n) {
        cin >> a[i];
        if( a[i] == -1 ) {
            now = i;
            continue;
        }
        child[a[i]-1] = i;
    }
    cout << now+1 << " ";
    while( child[now] != -1 ) {
        now = child[now];
        cout << now+1 << " ";
    }
    cout << endl;
    
    return 0;
}
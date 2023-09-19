/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc150/submissions/45717493
 * Submitted at: 2023-09-19 09:22:45
 * Problem URL: https://atcoder.jp/contests/abc150/tasks/abc150_c
 * Result: AC
 * Execution Time: 2 ms
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
    vector<ll> p(n), q(n);
    rep(i,n) cin >> p[i];
    rep(i,n) cin >> q[i];
    vector<ll> perm(n);
    iota(perm.begin(), perm.end(), 1);
    ll a, b, turn = 1;
    do { 
        ll cnt = 0;
        rep(i,n) cnt += (p[i] == perm[i]);
        if( cnt == n ) a = turn;
        cnt = 0;
        rep(i,n) cnt += (q[i] == perm[i]);
        if( cnt == n ) b = turn;

        turn++;
    } while(next_permutation(perm.begin(), perm.end()));
    cout << abs(a-b) << endl;
    
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/47067349
 * Submitted at: 2023-10-29 19:35:21
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_j
 * Result: AC
 * Execution Time: 188 ms
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

ll n;
vector<vector<vector<double>>> memo;
inline double f(ll c1, ll c2, ll c3) {
    double e = 0.0;
    if( c1 ) {
        if( memo[c1-1][c2][c3] < 0.0 ) memo[c1-1][c2][c3] = f(c1-1, c2, c3);
        e += memo[c1-1][c2][c3] * c1 / n;
    }
    if( c2 ) {
        if( memo[c1+1][c2-1][c3] < 0.0 ) memo[c1+1][c2-1][c3] = f(c1+1, c2-1, c3);
        e += memo[c1+1][c2-1][c3] * c2 / n;
    }
    if( c3 ) {
        if( memo[c1][c2+1][c3-1] < 0.0 ) memo[c1][c2+1][c3-1] = f(c1, c2+1, c3-1);
        e += memo[c1][c2+1][c3-1] * c3 / n;
    }
    if( c1+c2+c3 ) {
        e++;
        e *= (double)n / (c1+c2+c3);
    }
    memo[c1][c2][c3] = e;
    return e;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << setprecision(12) << fixed;
    
    cin >> n;
    vector<ll> a(n), cnt(4,0);
    memo.assign(n+1,vector(n+1,vector<double>(n+1,-1.0)));
    rep(i,n) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    cout << f(cnt[1], cnt[2], cnt[3]) << endl;
    
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc323/submissions/46288943
 * Submitted at: 2023-10-07 21:07:18
 * Problem URL: https://atcoder.jp/contests/abc323/tasks/abc323_b
 * Result: AC
 * Execution Time: 1 ms
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
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    priority_queue<P> todo;
    vector<ll> cnt(n,0);
    rep(i,n)rep(j,n) {
        if( s[i][j] == '-' ) continue;
        if( s[i][j] == 'o' ) cnt[i]++;
        else cnt[j]++;
    }
    rep(i,n) todo.push(P(cnt[i],n-i));
    while( !todo.empty() ) {
        auto [_,i] = todo.top(); todo.pop();
        i = n-i;
        cout << i+1 << " ";
    }
    cout << endl;
    
    return 0;
}
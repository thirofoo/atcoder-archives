/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc136/submissions/45952724
 * Submitted at: 2023-09-26 09:21:50
 * Problem URL: https://atcoder.jp/contests/arc136/tasks/arc136_a
 * Result: AC
 * Execution Time: 5 ms
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
    
    ll n; string s; cin >> n >> s;
    ll left = 0;
    rep(i,n) {
        if( s[i] == 'C' ) {
            sort(s.begin()+left, s.begin()+i);
            left = i+1;
        }
    }
    sort(s.begin()+left,s.end());
    rep(i,n) {
        if( i == n-1 ) cout << s[i];
        else if( s[i] == 'B' && s[i+1] == 'B' ) {
            cout << 'A';
            i++;
        }
        else cout << s[i];
    }
    cout << endl;
    
    return 0;
}
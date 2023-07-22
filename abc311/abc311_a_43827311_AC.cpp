/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc311/submissions/43827311
 * Submitted at: 2023-07-22 21:01:45
 * Problem URL: https://atcoder.jp/contests/abc311/tasks/abc311_a
 * Result: AC
 * Execution Time: 11 ms
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
    
    ll n; string s; cin >> n >> s;
    vector<ll> cnt(3,0);
    rep(i,n) {
        cnt[s[i]-'A']++;
        if( cnt[0] && cnt[1] && cnt[2] ) {
            cout << i+1 << endl;
            return 0;
        }
    }
    
    
    return 0;
}
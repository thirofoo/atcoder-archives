/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc181/submissions/43819397
 * Submitted at: 2023-07-22 15:53:58
 * Problem URL: https://atcoder.jp/contests/abc181/tasks/abc181_d
 * Result: WA
 * Execution Time: 8 ms
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
    
    string s; cin >> s;
    vector<ll> cnt(9,0);
    rep(i,s.size()) cnt[s[i]-'0']++;
    rep(i,1000){
        if( i%8 != 0 ) continue;
        bool f = true;
        ll now = i;
        rep(j,3) {
            f &= (cnt[now%10]);
            now /= 10;
        }
        if( f ) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc324/submissions/47610564
 * Submitted at: 2023-11-16 13:38:17
 * Problem URL: https://atcoder.jp/contests/abc324/tasks/abc324_c
 * Result: AC
 * Execution Time: 36 ms
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
    
    ll n; string t; cin >> n >> t;
    queue<ll> ans;
    rep(i,n) {
        string s; cin >> s;
        if( s.size() < t.size()-1 || t.size()+1 < s.size() ) continue;
        ll l = 0, r = 0;
        for(ll j=0; j<min(t.size(),s.size()); j++) {
            if( s[j] != t[j] ) break;
            l++;
        }
        for(ll j=0; j<min(t.size(),s.size()); j++) {
            if( s[s.size()-1-j] != t[t.size()-1-j] ) break;
            r++;
        }
        // cerr << l << " " << r << endl;
        if( s.size() == t.size()+1 ) (l+r >= t.size() ? ans.push(i+1) : void());
        else (l+r >= t.size()-1 ? ans.push(i+1) : void());
    }
    cout << ans.size() << endl;
    while( !ans.empty() ) {
        cout << ans.front() << " ";
        ans.pop();
    }
    cout << endl;
    
    return 0;
}
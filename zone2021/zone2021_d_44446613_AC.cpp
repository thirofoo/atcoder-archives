/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/zone2021/submissions/44446613
 * Submitted at: 2023-08-11 10:01:55
 * Problem URL: https://atcoder.jp/contests/zone2021/tasks/zone2021_d
 * Result: AC
 * Execution Time: 19 ms
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
    
    string s; cin >> s;
    deque<char> r;
    ll reverse = 0;
    rep(i,s.size()) {
        if( s[i] == 'R' ) reverse++;
        else {
            if( reverse%2 == 0 ) {
                if( !r.empty() && r.back() == s[i] ) r.pop_back();
                else r.push_back(s[i]);
            }
            else {
                if( !r.empty() && r.front() == s[i] ) r.pop_front();
                else r.push_front(s[i]);
            }
        }
    }
    if( reverse%2 == 0 ) {
        rep(i,r.size()) cout << r[i];
        cout << endl;
    }
    else {
        rep(i,r.size()) cout << r[r.size()-1-i];
        cout << endl;
    }
    
    return 0;
}
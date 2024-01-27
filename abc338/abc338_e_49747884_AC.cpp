/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc338/submissions/49747884
 * Submitted at: 2024-01-28 00:23:44
 * Problem URL: https://atcoder.jp/contests/abc338/tasks/abc338_e
 * Result: AC
 * Execution Time: 23 ms
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
    vector<ll> group(2*n,0);
    rep(i,n) {
        ll a, b; cin >> a >> b; a--, b--;
        group[a] = group[b] = i;
    }
    vector<bool> sec(n,false);
    stack<ll> st;
    rep(i,2*n) {
        if( !sec[group[i]] ) {
            sec[group[i]] = true;
            st.push(group[i]);
        } else {
            if( st.top() != group[i] ) {
                cout << "Yes" << endl;
                return 0;
            }
            st.pop();
        }
    }
    cout << "No" << endl;
    
    return 0;
}
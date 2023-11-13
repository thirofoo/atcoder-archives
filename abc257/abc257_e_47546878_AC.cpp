/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc257/submissions/47546878
 * Submitted at: 2023-11-13 16:01:22
 * Problem URL: https://atcoder.jp/contests/abc257/tasks/abc257_e
 * Result: AC
 * Execution Time: 52 ms
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
    vector<ll> c(9);
    ll ele = 0, mc = 1e9;
    rep(i,9) {
        cin >> c[i];
        if( mc >= c[i] ) {
            mc = c[i];
            ele = i;
        }
    }
    ll rest = n;
    priority_queue<ll,vector<ll>,greater<ll>> ans;
    while( rest >= c[ele] ) {
        ans.emplace(ele);
        rest -= c[ele];
    }
    for(ll i=8; i>ele; i--) {
        while( ans.top() < i && rest+c[ans.top()] >= c[i] ) {
            rest += c[ans.top()];
            ans.pop();
            ans.push(i);
            rest -= c[i];
        }
    }
    stack<ll> st;
    while( !ans.empty() ) {
        st.push(ans.top());
        ans.pop();
    }
    while( !st.empty() ) {
        cout << st.top()+1;
        st.pop();
    }
    cout << endl;
    
    return 0;
}
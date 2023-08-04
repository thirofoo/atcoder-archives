/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc123/submissions/44229904
 * Submitted at: 2023-08-04 19:08:21
 * Problem URL: https://atcoder.jp/contests/abc123/tasks/abc123_d
 * Result: AC
 * Execution Time: 17 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll, ll>;
using TT = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll x,y,z,k; cin >> x >> y >> z >> k;
    vector<ll> a(x), b(y), c(z);
    rep(i,x) cin >> a[i];
    rep(i,y) cin >> b[i];
    rep(i,z) cin >> c[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    priority_queue<ll,vector<ll>,greater<ll>> ans;
    priority_queue<T> todo;
    todo.push(T(a.back()+b.back()+c.back(),x-1,y-1,z-1));
    set<TT> st;
    while( !todo.empty() ) {
        auto [cost, i, j, l] = todo.top(); todo.pop();
        if( ans.size() == k && cost <= ans.top() ) continue;
        if( st.count(TT(i,j,l)) ) continue;
        st.insert(TT(i,j,l));
        ans.push(cost);
        if( ans.size() > k ) ans.pop();
        if( i != 0 ) todo.push(T(cost-a[i]+a[i-1],i-1,j,l));
        if( j != 0 ) todo.push(T(cost-b[j]+b[j-1],i,j-1,l));
        if( l != 0 ) todo.push(T(cost-c[l]+c[l-1],i,j,l-1));
    }
    stack<ll> answer;
    while( !ans.empty() ) {
        answer.push(ans.top());
        ans.pop();
    }
    while( !answer.empty() ) {
        cout << answer.top() << endl;
        answer.pop();
    }
    
    return 0;
}
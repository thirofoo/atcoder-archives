/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/adt_all_20231026_2/submissions/46962074
 * Submitted at: 2023-10-27 15:57:20
 * Problem URL: https://atcoder.jp/contests/adt_all_20231026_2/tasks/abc247_e
 * Result: WA
 * Execution Time: 114 ms
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
    
    ll n, x, y; cin >> n >> x >> y;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    multiset<ll> st;
    ll l = 0, r = 0, ans = 0;
    queue<ll> sx, sy;
    while(l < n){
        if(r == n || ( !st.empty() && ((*st.begin()) < y || x < (*st.rbegin())) ) ){
            st.erase(st.find(a[l]));
            while( !sx.empty() && sx.front() <= l ) sx.pop();
            while( !sy.empty() && sy.front() <= l ) sy.pop();
            if( !sx.empty() && !sy.empty() ) ans += r - max(sx.front(), sy.front());
            ++l;
        }
        else{
            if( a[r] == x ) sx.push(r);
            if( a[r] == y ) sy.push(r);
            st.insert(a[r]);
            if( !st.empty() && y == (*st.begin()) && (*st.rbegin()) == x ) ans++;
            ++r;
        }
    }
    cout << ans << endl;
    
    return 0;
}
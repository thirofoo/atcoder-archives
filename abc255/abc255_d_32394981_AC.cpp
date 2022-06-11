/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc255/submissions/32394981
 * Submitted at: 2022-06-11 21:44:49
 * Problem URL: https://atcoder.jp/contests/abc255/tasks/abc255_d
 * Result: AC
 * Execution Time: 399 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll n,q; cin >> n >> q;
    vector<ll> a(n);
    rep(i,n)cin >> a[i];
    sort(a.begin(),a.end());

    vector<ll> front(n+1,0),back(n+1,0);
    rep(i,n)front[i+1] = front[i]+a[i];
    reverse(a.begin(),a.end());
    rep(i,n)back[i+1] = back[i]+a[i];
    reverse(a.begin(),a.end());

    while(q--){
        ll x; cin >> x;
        ll idx = upper_bound(a.begin(),a.end(),x)-a.begin();
        cout << x*idx-front[idx] + back[n-idx]-x*(n-idx) << endl;
    }
    return 0;
}
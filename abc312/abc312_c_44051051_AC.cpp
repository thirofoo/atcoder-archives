/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc312/submissions/44051051
 * Submitted at: 2023-07-29 21:28:33
 * Problem URL: https://atcoder.jp/contests/abc312/tasks/abc312_c
 * Result: AC
 * Execution Time: 84 ms
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
    
    ll n,m; cin >> n >> m;
    vector<ll> a(n),b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    ll left = 0, right = 1e16;
    while(right-left > 1){
        ll mid = (right+left)/2;
        ll cnt1 = 0, cnt2 = 0;
        rep(i,n) if(mid >= a[i]) cnt1++;
        rep(i,m) if(mid <= b[i]) cnt2++;
        if( cnt1 >= cnt2 ) right = mid;
        else left = mid;
    }
    cout << right << endl;
    
    return 0;
}
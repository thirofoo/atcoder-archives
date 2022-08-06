/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc263/submissions/33833790
 * Submitted at: 2022-08-06 22:11:50
 * Problem URL: https://atcoder.jp/contests/abc263/tasks/abc263_d
 * Result: AC
 * Execution Time: 34 ms
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
    
    ll n,l,r; cin >> n >> l >> r;
    vector<ll> a(n),left(n),right(n);
    ll total = 0;
    rep(i,n){
        cin >> a[i];
        total += a[i];
    }
    left = a; right = a;
    rep(i,n-1)left[i+1] += left[i];
    for(int i=n-1;i>=1;i--)right[i-1] += right[i];
    rep(i,n)left[i] -= (i+1)*l;
    for(int i=n-1;i>=0;i--)right[i] -= (n-i)*r;
    for(int i=n-1;i>=1;i--)right[i-1] = max(right[i],right[i-1]);

    ll ans = 0;
    rep(i,n+1){
        if(i == 0){
            ans = max(ans,right[0]);
        }
        else if(i == n){
            ans = max(ans,left[n-1]);
        }
        else{
            ans = max(ans,left[i-1]+right[i]);
            ans = max(ans,left[i-1]);
        }
    }
    cout << total - ans << endl;

    
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc144/submissions/33266134
 * Submitted at: 2022-07-16 21:46:21
 * Problem URL: https://atcoder.jp/contests/arc144/tasks/arc144_b
 * Result: WA
 * Execution Time: 147 ms
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
    
    ll n,a,b,left = 1,right = -1; cin >> n >> a >> b;
    vector<ll> A(n);
    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());
    rep(i,n){
        cin >> A[i];
        right = max(right,A[i]);
    }
    while(right-left > 1){
        ll mid = (right+left)/2;
        ll cnt = 0;
        rep(i,n){
            if(A[i] >= mid){
                cnt += (A[i]-mid)/b;
            }
            else{
                cnt -= (mid-A[i])/a;
                if((mid-A[i])%a != 0)cnt--;
            }
        }
        if(cnt >= 0)left = mid;
        else right = mid;
    }
    cout << left << endl;
    
    return 0;
}
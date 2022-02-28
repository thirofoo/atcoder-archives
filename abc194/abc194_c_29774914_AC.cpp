/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc194/submissions/29774914
 * Submitted at: 2022-02-28 21:44:07
 * Problem URL: https://atcoder.jp/contests/abc194/tasks/abc194_c
 * Result: AC
 * Execution Time: 66 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n; cin >> n;
    ll ans = 0;
    vector<ll> a(n),a1(n),a2(n);
    rep(i,n){
        cin >> a[i];
        if(i == 0){
            a1[i] = a[i];
            a2[i] = a[i]*a[i];
        }
        else{
            a1[i] = a[i]+a1[i-1];
            a2[i] = a[i]*a[i]+a2[i-1];
        }
    }
    for(int i=1;i<n;i++){
        ans += i*pow(a[i],2)-2*a1[i-1]*a[i]+a2[i-1];
    }
    cout << ans << endl;
    return 0;
}
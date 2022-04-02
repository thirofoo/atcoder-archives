/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc246/submissions/30674124
 * Submitted at: 2022-04-02 22:59:29
 * Problem URL: https://atcoder.jp/contests/abc246/tasks/abc246_d
 * Result: AC
 * Execution Time: 97 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

ll f(ll a,ll b){
    return a*a*a + a*a*b + a*b*b + b*b*b;
}

int main() {
    ll n,ans = -INT_MAX; cin >> n;
    if(n == 0)return cout << n << endl,0;
    for(int a=0;a<=1000000;a++){
        ll left = 0,right = 1000000;
        while(right-left > 1){
            ll mid = (left+right)/2;
            ll tmp = f(a,mid);
            if(tmp < n)left = mid;
            else right = mid;
        }
        if(ans == -INT_MAX)ans = f(a,right);
        else ans = (ans-n <= f(a,right)-n ? ans : f(a,right));
    }
    cout << ans << endl;
    return 0;
}
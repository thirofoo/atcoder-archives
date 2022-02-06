/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc238/submissions/29132652
 * Submitted at: 2022-02-06 23:10:16
 * Problem URL: https://atcoder.jp/contests/abc238/tasks/abc238_c
 * Result: AC
 * Execution Time: 5 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

ll mod = 998244353;

int main() {
    ll n,ans = 0,zyo = 1; cin >> n;
    for(int i=1;i<=18;i++){
        zyo *= (ll)10;
        if(n > zyo-1){
            ans += ((zyo-zyo/(ll)10)%mod)*((zyo-zyo/(ll)10+(ll)1)%mod)/(ll)2;
        }
        else{
            ans += ((n-zyo/(ll)10+(ll)1)%mod)*((n-zyo/(ll)10+(ll)2)%mod)/(ll)2;
            break;
        }
        ans %= mod;
    }
    cout << ans%mod << endl;
    return 0;
}
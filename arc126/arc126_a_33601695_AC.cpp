/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc126/submissions/33601695
 * Submitted at: 2022-07-30 11:26:37
 * Problem URL: https://atcoder.jp/contests/arc126/tasks/arc126_a
 * Result: AC
 * Execution Time: 7 ms
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
    
    ll t; cin >> t;
    while(t--){
        ll n2,n6,n4; cin >> n2 >> n6 >> n4;
        n6 /= 2;
        ll ans = 0;
        //6-4part
        if(n6 >= n4){
            ans += n4;
            n6 -= n4; n4 = 0;
        }
        else{
            ans += n6;
            n4 -= n6; n6 = 0;
        }

        //6-2-2part
        if(n6 >= n2/2){
            ans += n2/2;
            n6 -= n2/2,n2 %= 2;
        }
        else{
            ans += n6;
            n2 -= n6*2,n6 = 0;
        }

        //4-4-2part
        if(n4/2 >= n2){
            ans += n2;
            n4 -= n2*2,n2 = 0; 
        }
        else{
            ans += n4/2;
            n2 -= n4/2; n4 %= 2;
        }

        //4-2-2-2part
        if(n4 >= n2/3){
            ans += n2/3;
            n4 -= n2/3,n2 %= 3;
        }
        else{
            ans += n4;
            n2 -= n4*3,n4 = 0;
        }

        //2-2-2-2-2part
        if(n2/5){
            ans += n2/5;
            n2 %= 5;
        }


        cout << ans << endl;
    }
    
    return 0;
}
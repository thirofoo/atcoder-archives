/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc145/submissions/33627617
 * Submitted at: 2022-07-30 22:04:27
 * Problem URL: https://atcoder.jp/contests/arc145/tasks/arc145_b
 * Result: WA
 * Execution Time: 8 ms
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

ll euclid(ll a,ll b){
    if(b != 0)return euclid(b,a%b);
    else return a;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll n,a,b; cin >> n >> a >> b;
    if(a <= b)cout << n << endl;
    else{
        ll ans = (n/a)*b - b;
        if(n%a < b)ans += n%a+1;
        else {
            ans += b;
        }
        cout << ans << endl;
    }
    
    return 0;
}
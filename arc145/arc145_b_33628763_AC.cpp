/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc145/submissions/33628763
 * Submitted at: 2022-07-30 22:10:44
 * Problem URL: https://atcoder.jp/contests/arc145/tasks/arc145_b
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

ll euclid(ll a,ll b){
    if(b != 0)return euclid(b,a%b);
    else return a;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll n,a,b; cin >> n >> a >> b;
    if(a <= b)cout << (n >= a ? n-a+1 : 0) << endl;
    else{
        ll ans = (n/a)*b - b;
        if(n%a < b)ans += n%a+1;
        else ans += b;
        cout << (ans < 0 ? 0 : ans) << endl;
    }
    
    return 0;
}
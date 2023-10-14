/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ttpc2023/submissions/46512550
 * Submitted at: 2023-10-14 16:24:38
 * Problem URL: https://atcoder.jp/contests/ttpc2023/tasks/ttpc2023_l
 * Result: WA
 * Execution Time: 84 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

inline long long GCD(long long a, long long b){
    // 負 or a == 0 で -1
    if( a <= 0 || b < 0 ) return -1;
    if( b != 0 ) return GCD(b,a%b);
    return a;
}

inline long long LCM(long long a, long long b){
    // 負 or overflow の時は -1
    if( a < 0 || b < 0 ) return -1;
    if( (a / GCD(a,b)) >= 1e18 / b ) return -1;
    return a  / GCD(a,b) * b;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    string s1, s2, s3, s4; cin >> s1 >> s2 >> s3 >> s4;
    if( s1.size() > 50 || s2.size() > 50 || s3.size() > 50 || s4.size() > 50 ) return cout << -1 << endl ,0;

    ll T = LCM(LCM(LCM(s1.size(),s2.size()),s3.size()),s4.size());
    vector<ll> ok;
    rep(i,T) {
        string ttpc = "";
        ttpc += s1[i%s1.size()];
        ttpc += s2[i%s2.size()];
        ttpc += s3[i%s3.size()];
        ttpc += s4[i%s4.size()];
        if( ttpc == "TTPC" ) ok.emplace_back(i+1);
    }
    if( ok.empty() ) return cout << -1 << endl,0;
    cout << ( n >= ok.size() ? ((n-ok.size())/ok.size())*T : 0 ) + ok[(n-1)%ok.size()] << endl;
    
    return 0;
}
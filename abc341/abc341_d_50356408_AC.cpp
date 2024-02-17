/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc341/submissions/50356408
 * Submitted at: 2024-02-17 21:27:10
 * Problem URL: https://atcoder.jp/contests/abc341/tasks/abc341_d
 * Result: AC
 * Execution Time: 1 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

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
    
    ll n, m, k; cin >> n >> m >> k;
    ll lcm = LCM(n, m);
    ll left = 0, right = 1e18;
    while(right - left > 1) {
        ll mid = (left + right) / 2;
        ll cnt = mid/n + mid/m - (mid/lcm)*2;
        // cerr << left << " " << right << " " << cnt << " " << mid << '\n';
        if(cnt < k) left = mid;
        else right = mid;
    }
    // cerr << left << " " << right << '\n';
    cout << left+1 << '\n';
    
    return 0;
}
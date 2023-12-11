/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/48434724
 * Submitted at: 2023-12-12 01:27:23
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_i
 * Result: WA
 * Execution Time: 2210 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
    // 小数第10位まで出力
    cout << setprecision(10) << fixed;
    ll n; cin >> n;
    vector<ld> p(n);
    for(ll i=0; i<n; i++) cin >> p[i];

    ld ans = 0.0;
    for(ll i=0; i<(1LL << n); i++) {
        ll omote = 0;
        ld cand = 1.0;
        for(ll j=0; j<n; j++) {
            // i の j 桁目の bit が立ってたら表、ないなら裏
            if( i & (1LL << j) ) {
                cand *= p[j];
                omote++;
            }
            else cand *= 1-p[j];
        }
        // 表の数 > 裏の数
        if( omote > n-omote ) ans += cand;
    }
    cout << ans << '\n';
    return 0;
}
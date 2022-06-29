/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc054/submissions/32832942
 * Submitted at: 2022-06-29 19:35:54
 * Problem URL: https://atcoder.jp/contests/arc054/tasks/arc054_b
 * Result: AC
 * Execution Time: 10 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << fixed;

    ld p; cin >> p;
    // x年後にはtakahashiman関数が(右辺)の時間で計算可能という式。
    auto f = [p](ld x){
        return x + p/pow(2,x/1.5);
    };
    ld left = 0,right = 1e10;
    while(right-left > 0.000000001){
        ld c1 = (left + left + right)/3;
        ld c2 = (left + right + right)/3;
        if(f(c1) >= f(c2))left = c1;
        else right = c2;
    }
    cout << f(left) << endl;
    
    return 0;
}
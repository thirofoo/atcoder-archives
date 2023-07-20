/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc165/submissions/43783210
 * Submitted at: 2023-07-20 23:42:28
 * Problem URL: https://atcoder.jp/contests/abc165/tasks/abc165_e
 * Result: AC
 * Execution Time: 153 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説AC ARC like
    ll n,m; cin >> n >> m;
    // i1, i2 : 奇数偶数の開始点
    ll i1 = 1, i2 = m+2;
    for(ll i=m;i>=1;i--){
        cout << i1 << " " << i1 + i << endl;
        i1++;
        swap(i1, i2);
    }
    
    return 0;
}
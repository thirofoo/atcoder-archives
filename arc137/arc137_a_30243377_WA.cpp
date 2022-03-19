/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc137/submissions/30243377
 * Submitted at: 2022-03-19 22:33:38
 * Problem URL: https://atcoder.jp/contests/arc137/tasks/arc137_a
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
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

ll GCD(ll A, ll B) {
    if (B == 0) return A;
    else return GCD(B, A % B);
}

int main() {
    ll l,r; cin >> l >> r;
    ll l1 = l,r1 = r;
    if(l == 1)return cout << r-l << endl,0;

    ll ans = 0;
    while(true){
        ll tmp1 = GCD(l1,r1);
        if(tmp1 == 1){
            ans = max(r1-l1,ans);
            l1++; r1 = r;
            if(r1-l1 <= ans)break;
        }
        r1--;
    }
    cout << ans << endl;

    return 0;
}
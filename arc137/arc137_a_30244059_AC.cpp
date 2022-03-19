/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc137/submissions/30244059
 * Submitted at: 2022-03-19 22:39:42
 * Problem URL: https://atcoder.jp/contests/arc137/tasks/arc137_a
 * Result: AC
 * Execution Time: 9 ms
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

    l1 = l,r1 = r;
    while(true){
        ll tmp1 = GCD(l1,r1);
        if(tmp1 == 1){
            ans = max(r1-l1,ans);
            r1--; l1 = l;
            if(r1-l1 <= ans)break;
        }
        l1++;
    }
    cout << ans << endl;

    return 0;
}
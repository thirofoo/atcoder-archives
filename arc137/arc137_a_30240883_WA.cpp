/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc137/submissions/30240883
 * Submitted at: 2022-03-19 22:12:45
 * Problem URL: https://atcoder.jp/contests/arc137/tasks/arc137_a
 * Result: WA
 * Execution Time: 5 ms
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
    if(l == 1)cout << r-l << endl;
    else{
        ll t1,t2,l1 = l,l2 = l,r1 = r,r2 = r;
        while(true){
            ll tmp1 = GCD(l1,r1);
            if(tmp1 == 1){
                t1 = r1-l1;
                break;
            }
            r1--;
        }
        while(true){
            ll tmp2 = GCD(l2,r2);
            if(tmp2 == 1){
                t2 = r2-l2;
                break;
            }
            l2++;
        }
        cout << max(t1,t2) << endl;
    }
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc137/submissions/30240058
 * Submitted at: 2022-03-19 22:06:42
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

long long GCD(long long A, long long B) {
    if (B == 0) return A;
    else return GCD(B, A % B);
}

int main() {
    ll l,r; cin >> l >> r;
    if(l == 1)cout << r-l << endl;
    else{
        while(true){
            ll tmp = GCD(l,r);
            if(tmp == 1)return cout << r-l << endl,0;
            r--;
        }
    }
    return 0;
}
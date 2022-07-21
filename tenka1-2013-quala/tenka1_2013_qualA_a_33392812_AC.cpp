/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/tenka1-2013-quala/submissions/33392812
 * Submitted at: 2022-07-21 18:23:37
 * Problem URL: https://atcoder.jp/contests/tenka1-2013-quala/tasks/tenka1_2013_qualA_a
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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll tmp = 42;
    while(tmp < 130000000){
        tmp += tmp;
    }
    cout << tmp << endl;

    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc128/submissions/31711906
 * Submitted at: 2022-05-15 18:13:14
 * Problem URL: https://atcoder.jp/contests/arc128/tasks/arc128_b
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
    
    int t; cin >> t;
    while(t--){
        ll r,g,b; cin >> r >> g >> b;
        ll cand = LLONG_MAX;

        if((r-g)%3 == 0)cand = min(max(r,g),cand);
        if((g-b)%3 == 0)cand = min(max(g,b),cand);
        if((b-r)%3 == 0)cand = min(max(b,r),cand);

        cout << (cand == LLONG_MAX ? -1 : cand) << endl;
    }   
    return 0;
}
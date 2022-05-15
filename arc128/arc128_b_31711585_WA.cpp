/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc128/submissions/31711585
 * Submitted at: 2022-05-15 17:58:11
 * Problem URL: https://atcoder.jp/contests/arc128/tasks/arc128_b
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
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int t; cin >> t;
    rep(i,t){
        ll r,g,b; cin >> r >> g >> b;
        ll cand = LLONG_MAX;

        if((r-g)%3 == 0 && abs(r-g)/3 <= b)cand = min(max(r,g),cand);
        if((g-b)%3 == 0 && abs(g-b)/3 <= r)cand = min(max(g,b),cand);
        if((b-r)%3 == 0 && abs(b-r)/3 <= g)cand = min(max(b,r),cand);

        cout << (cand == LLONG_MAX ? -1 : cand) << endl;
    }   
    return 0;
}
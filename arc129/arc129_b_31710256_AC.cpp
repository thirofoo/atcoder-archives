/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc129/submissions/31710256
 * Submitted at: 2022-05-15 16:59:33
 * Problem URL: https://atcoder.jp/contests/arc129/tasks/arc129_b
 * Result: AC
 * Execution Time: 333 ms
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
    
    int n,left = -INT_MAX,right = INT_MAX; cin >> n;
    rep(i,n){
        int l,r; cin >> l >> r;
        left = max(left,l);
        right = min(right,r);
        if(left-right <= 0)cout << 0 << endl;
        else cout << (left-right+1)/2 << endl;
    }
    
    return 0;
}
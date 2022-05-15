/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc128/submissions/31710963
 * Submitted at: 2022-05-15 17:30:18
 * Problem URL: https://atcoder.jp/contests/arc128/tasks/arc128_b
 * Result: WA
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
    rep(i,t){
        int r,g,b; cin >> r >> g >> b;
        if((r-g)%3 == 0){
            cout << max(r,g) << endl;
        }   
        else if((g-b)%3 == 0){
            cout << max(g,b) << endl;
        }
        else if((b-r)%3 == 0){
            cout << max(b,r) << endl;
        }
        else cout << -1 << endl;
    }   
    return 0;
}
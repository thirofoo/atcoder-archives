/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc113/submissions/31503116
 * Submitted at: 2022-05-08 11:02:22
 * Problem URL: https://atcoder.jp/contests/abc113/tasks/abc113_b
 * Result: AC
 * Execution Time: 5 ms
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
    
    long double n,t,a,tmp = INT_MAX,ans = -1; cin >> n >> t >> a;
    rep(i,n){
        long double h; cin >> h;
        if(abs(a-(t-0.006*h)) < tmp){
            tmp = abs(a-(t-0.006*h));
            ans = i+1;
        }
    }
    cout << ans << endl;

    return 0;
}
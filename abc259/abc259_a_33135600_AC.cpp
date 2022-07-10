/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc259/submissions/33135600
 * Submitted at: 2022-07-10 09:32:00
 * Problem URL: https://atcoder.jp/contests/abc259/tasks/abc259_a
 * Result: AC
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
    
    int n,m,x,t,d; cin >> n >> m >> x >> t >> d;
    cout << t - (m <= x ? (x-m)*d : 0 )  << endl;
    
    return 0;
}
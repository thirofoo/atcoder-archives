/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc253/submissions/32023606
 * Submitted at: 2022-05-28 21:28:47
 * Problem URL: https://atcoder.jp/contests/abc253/tasks/abc253_d
 * Result: WA
 * Execution Time: 17 ms
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

ll sigma(ll a){
    return a*(a+1)/2;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll n,a,b; cin >> n >> a >> b;
    cout << sigma(n) - a*sigma(n/a) - b*sigma(n/b) + sigma(n/(a*b))*a*b << endl;
    return 0;
}
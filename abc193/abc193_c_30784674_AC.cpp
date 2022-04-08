/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc193/submissions/30784674
 * Submitted at: 2022-04-08 13:29:32
 * Problem URL: https://atcoder.jp/contests/abc193/tasks/abc193_c
 * Result: AC
 * Execution Time: 40 ms
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

int main() {
    ll n; cin >> n;
    ll ans = 0;
    map<ll,ll> first;
    for(ll a=2;a*a<=n;a++){
        ll cnt = 2;
        while(n >= (ll)pow(a,cnt)){
            if(!first[(ll)pow(a,cnt)]){
                first[(ll)pow(a,cnt)]++;
                ans++;
            }
            cnt++;
        }
    }
    cout << n-ans << endl;
    return 0;
}
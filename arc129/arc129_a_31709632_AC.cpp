/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc129/submissions/31709632
 * Submitted at: 2022-05-15 16:36:39
 * Problem URL: https://atcoder.jp/contests/arc129/tasks/arc129_a
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
    
    ll n,l,r,ans = 0; cin >> n >> l >> r;
    ll k = log2(l);

    while(true){
        ll left = max((ll)pow(2,k),l);
        ll right = min((ll)pow(2,k+1),r+1);
        if(right < left)break;
        if(n & (1LL << k))ans += right-left;
        k++;
    }
    cout << ans << endl;
    return 0;
}
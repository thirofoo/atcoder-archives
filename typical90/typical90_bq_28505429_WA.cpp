/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28505429
 * Submitted at: 2022-01-14 18:26:57
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_bq
 * Result: WA
 * Execution Time: 10 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int s = 1000000007;

int main() {
    int n,k,count = 1; cin >> n >> k;
    vector<ll> mod(64);
    mod[0] = k-2;
    for(int i=0;i<63;i++){
        ll tmp = mod[i];
        mod[i+1] = (tmp*tmp)%s;
    }
    ll ans = k*(k-1)%s;
    rep(i,64){
        if((n-2)&(1LL << i)) (ans *= mod[i]) %= s;
    }
    cout << ans << endl;
    return 0;
}
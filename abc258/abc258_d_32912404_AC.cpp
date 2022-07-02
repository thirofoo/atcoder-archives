/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc258/submissions/32912404
 * Submitted at: 2022-07-02 21:46:39
 * Problem URL: https://atcoder.jp/contests/abc258/tasks/abc258_d
 * Result: AC
 * Execution Time: 49 ms
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
    
    ll n,x,ans = LLONG_MAX,now = 0,mi = LLONG_MAX; cin >> n >> x;
    vector<P> q;
    rep(i,n){
        ll a,b; cin >> a >> b;
        q.push_back(P(a,b));
    }
    rep(i,n){
        if(x-i-1 < 0)break;
        now += q[i].first+q[i].second;
        ll tx = i+1,tmp = now;
        mi = min(mi,q[i].second);
        tmp += mi*(x-tx);
        ans = min(ans,tmp);
    }
    cout << ans << endl;
    
    return 0;
}
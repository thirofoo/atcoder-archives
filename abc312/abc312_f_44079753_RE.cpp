/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc312/submissions/44079753
 * Submitted at: 2023-07-29 22:39:07
 * Problem URL: https://atcoder.jp/contests/abc312/tasks/abc312_f
 * Result: RE
 * Execution Time: 144 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 缶切りは多い方から使った方が良い
    ll n,m; cin >> n >> m;
    vector<P> kan;
    vector<ll> kankiri;
    ll ans = 0;
    rep(i,n){
        ll t,x; cin >> t >> x;
        if( t == 0 || t == 1 ) {
            kan.push_back(P(t,x));
            if( t == 0 ) ans += x;
        }
        else kankiri.push_back(x);
    }
    sort(kan.begin(),kan.end(),[](P p1, P p2){
        if( p1.second == p2.second ) return p1.first < p2.first;
        return p1.second > p2.second;
    });
    sort(kankiri.begin(),kankiri.end());
    reverse(kankiri.begin(),kankiri.end());

    vector<ll> r1(kan.size()+1,0), r2(kan.size()+1,0), num1(kan.size()+1,0), num2(kan.size()+1,0);
    rep(i,kan.size()){
        auto [t,x] = kan[i];
        if( t == 0 ) {
            r1[i+1] += x;
            r1[i+1]++;
        }
        else {
            r2[i+1] += x;
            num2[i+1]++;
        }
        r1[i+1] += r1[i];
        r2[i+1] += r2[i];
        num1[i+1] += num1[i];
        num2[i+1] += num2[i];
    }

    // 缶切り全探索
    ll cnt = 0;
    rep(i,kankiri.size()){
        cnt += kankiri[i];
        ll left = 0, right = kan.size()+1;
        while(right-left > 1) {
            ll mid = (right+left)/2;
            if( num2[mid] <= cnt) left = mid;
            else right = mid;
        }

        if( left >= m-(i+1) ) {
            ans = max(ans, r1[m-(i+1)] + r2[m-(i+1)]);
        }
        else {
            ll cand = r2[left];
            auto itr = lower_bound(num1.begin(),num1.end(),m-(i+1)-num2[left]);
            cand += r1[itr-num1.begin()+1];
            ans = min(ans,cand);
        }
    }
    cout << ans << endl;
    
    return 0;
}
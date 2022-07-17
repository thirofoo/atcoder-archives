/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc144/submissions/33281382
 * Submitted at: 2022-07-17 12:04:03
 * Problem URL: https://atcoder.jp/contests/arc144/tasks/arc144_c
 * Result: AC
 * Execution Time: 136 ms
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
    
    ll n,k; cin >> n >> k;
    if(n < k*2)return cout << -1 << endl,0;
    set<ll> now;
    rep(i,n)now.insert(i+1);
    rep(i,n){
        ll tmp = *now.lower_bound(1);
        if(now.count(i+1+k) && i+1+2*k > n){
            cout << i+1+k << " ";
            now.erase(i+1+k);
        }
        else if(tmp <= i+1-k){
            cout << tmp << " ";
            now.erase(tmp);
        }
        else{
            cout << *now.lower_bound(i+1+k) << " ";
            now.erase(*now.lower_bound(i+1+k));
        }
    }
    cout << endl;
    
    return 0;
}
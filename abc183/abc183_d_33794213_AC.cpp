/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc183/submissions/33794213
 * Submitted at: 2022-08-06 14:40:43
 * Problem URL: https://atcoder.jp/contests/abc183/tasks/abc183_d
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
    
    ll n,w; cin >> n >> w;
    vector<ll> imos(200005,0);
    rep(i,n){
        ll s,t,p; cin >> s >> t >> p;
        imos[s] += p;
        imos[t] -= p;
    }
    rep(i,200004)imos[i+1] += imos[i];
    rep(i,200005){
        if(imos[i] > w)return cout << "No" << endl,0;
    }
    cout << "Yes" << endl;

    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc259/submissions/33129918
 * Submitted at: 2022-07-10 00:04:31
 * Problem URL: https://atcoder.jp/contests/abc259/tasks/abc259_e
 * Result: AC
 * Execution Time: 346 ms
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
    
    ll n,sum = 1; cin >> n;
    vector<vector<P>> prime(n);
    map<ll,P> prime_num;
    rep(i,n){
        ll m; cin >> m;
        rep(j,m){
            ll p,e; cin >> p >> e;
            prime[i].push_back(P(p,e));
            auto [s,cnt] = prime_num[p];
            if(e > s){
                prime_num[p] = P(e,1);
            }
            else if(e == s){
                prime_num[p] = P(e,cnt+1);
            }
        }
    }

    ll ans = 0;
    map<ll,bool> a;
    bool F = false;
    rep(i,n){
        bool f = true;
        for(auto [pr,e]:prime[i]){
            auto [e2,c2] = prime_num[pr];
            if(e == e2 && c2 == 1 && !a[pr]){
                a[pr] = true;
                if(f){
                    ans++;
                    f = false;
                }
            }
        }
        F |= f;
    }
    cout << ans + (F ? 1 : 0) << endl;
    return 0;
}
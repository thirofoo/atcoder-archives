/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc180/submissions/36156207
 * Submitted at: 2022-11-02 19:22:08
 * Problem URL: https://atcoder.jp/contests/abc180/tasks/abc180_e
 * Result: AC
 * Execution Time: 63 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
template<class T, class... Ts> void print(const T& a, const Ts&... b){cout << a;(cout << ... << (cout << ' ', b));cout << '\n';}
template<class... T> void input(T&... a){(cin >> ... >> a);}
void print(){cout << '\n';}
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    vector<T> p;
    rep(i,n){
        ll x,y,z; input(x,y,z);
        p.push_back(T(x,y,z));
    }
    vector<vector<ll>> dp((1LL << n),vector<ll>(n,LLONG_MAX));
    dp[1][0] = 0;
    rep(i,(1LL << n)){
        rep(j,n){
            if(dp[i][j] == LLONG_MAX)continue;
            auto [x,y,z] = p[j];
            rep(to,n){
                if(to == j)continue;
                auto [nx,ny,nz] = p[to];
                ll next = i | (1LL << to);
                dp[next][to] = min(dp[next][to],dp[i][j]+abs(x-nx)+abs(y-ny)+max(0LL,nz-z));
            }
        }
    }
    ll ans = LLONG_MAX;
    auto [sx,sy,sz] = p[0];
    rep(i,n){
        auto [x,y,z] = p[i];
        ans = min(ans,dp[(1LL << n)-1][i]+abs(sx-x)+abs(sy-y)+max(0LL,sz-z));
    }
    print(ans);
    
    return 0;
}
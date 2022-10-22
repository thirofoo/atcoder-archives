/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc274/submissions/35903863
 * Submitted at: 2022-10-23 00:58:21
 * Problem URL: https://atcoder.jp/contests/abc274/tasks/abc274_e
 * Result: AC
 * Execution Time: 149 ms
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
typedef tuple<ll, ll, ld, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << setprecision(7) << fixed;
    
    ll n,m; input(n,m);
    vector<P> p;
    p.push_back(P(0,0));
    rep(i,n+m){
        ll x,y; input(x,y);
        p.push_back(P(x,y));
    }

    ld ans = LLONG_MAX;
    ll mask = (1LL << n)-1;
    vector<vector<ld>> dp((1LL << (n+m)),vector<ld>(n+m+1,LLONG_MAX));
    dp[0][0] = 0;
    rep(i,(1LL << (n+m))){
        ld v = 1;
        for(int j=n;j<n+m;j++)if(i & (1LL << j))v *= 2;

        rep(j,n+m+1){
            if(dp[i][j] == LLONG_MAX)continue;
            auto [x1,y1] = p[j];

            rep(k,n+m){
                if(i & (1LL << k))continue;
                ll to = i | (1LL << k);
                auto [x2,y2] = p[k+1];
                ld ns = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))/v;
                dp[to][k+1] = min(dp[to][k+1],dp[i][j]+ns);
            }
            if((i & mask) == mask)ans = min(ans,dp[i][j]+sqrt(x1*x1+y1*y1)/v);
        }
    }
    print(ans);
    
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc274/submissions/35901009
 * Submitted at: 2022-10-22 23:30:17
 * Problem URL: https://atcoder.jp/contests/abc274/tasks/abc274_e
 * Result: TLE
 * Execution Time: 2266 ms
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
    rep(i,n+m){
        ll x,y; input(x,y);
        p.push_back(P(x,y));
    }
    p.push_back(P(0,0));
    vector<vector<ld>> dp((1LL << n+m),vector<ld>(n+m+1,LLONG_MAX));
    // T(状態,最後の場所,スコア,速度)
    queue<T> todo;
    todo.push(T(0,n+m,0,1));
    while(!todo.empty()){
        auto [x,last,c,v] = todo.front(); todo.pop();
        if(dp[x][last] <= c)continue;
        dp[x][last] = c;
        rep(i,n+m){
            if(x & (1LL << i))continue;
            auto [x1,y1] = p[i];
            auto [x2,y2] = p[last];
            ld nc = c + sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) )/v;
            ll nx = x | (1LL << i);
            todo.push(T( nx, i, nc, v*(i >= n ? 2 : 1) ));
        }
    }

    ld ans = LLONG_MAX;
    ll mask = (1LL << n)-1;
    rep(i,(1LL << (n+m))){
        if((i & mask) != mask)continue;
        rep(j,n+m+1){
            ll v = 1;
            for(int k=n;k<n+m;k++)if(i & (1LL << k))v *= 2;
            ans = min(ans,dp[i][j]+sqrt(p[j].first*p[j].first + p[j].second*p[j].second)/v);
        }
    }
    print(ans);
    
    return 0;
}
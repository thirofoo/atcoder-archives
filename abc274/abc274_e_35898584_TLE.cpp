/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc274/submissions/35898584
 * Submitted at: 2022-10-22 22:51:19
 * Problem URL: https://atcoder.jp/contests/abc274/tasks/abc274_e
 * Result: TLE
 * Execution Time: 2258 ms
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
    cout << setprecision(10) << fixed;
    
    ll n,m; input(n,m);
    vector<P> p;
    rep(i,n+m){
        ll x,y; input(x,y);
        p.push_back(P(x,y));
    }
    vector<vector<ld>> dp((1LL << (n+m)),vector<ld>(n+m,LLONG_MAX));
    // T(状態,最後の場所,スコア,速度)
    bool f = true;
    queue<T> todo;
    ld ans = LLONG_MAX;
    ll mask = (1LL << n)-1;
    todo.push(T(0,0,0,1));
    while(!todo.empty()){
        auto [x,last,c,v] = todo.front(); todo.pop();
        if(dp[x][last] <= c)continue;
        dp[x][last] = c;
        rep(i,n+m){
            if(x & (1LL << i))continue;
            ll px = (f ? 0 : p[last].first);
            ll py = (f ? 0 : p[last].second);
            ld score = sqrt( (p[i].first-px)*(p[i].first-px) + ((p[i].second-py)*(p[i].second-py)) )/v;
            if(dp[x|(1LL << i)][i] > c+score)todo.push(T( x|(1LL << i), i, c+score, v*(i >= n ? 2 : 1) ));
        }
        f = false;
    }

    rep(i,(1LL << (n+m))){
        if((i & mask) != mask)continue;
        rep(j,n+m+1){
            ll v = 1;
            for(int k=n;k<n+m;k++)if(i & (1LL << k))v *= 2;
            ans = min(ans,dp[i][j]+sqrt(p[j].first*p[j].first + p[j].second*p[j].second)/v);
            // print(ans,i,j,v);
        }
    }
    print(ans);
    
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc032/submissions/40596242
 * Submitted at: 2023-04-14 09:15:44
 * Problem URL: https://atcoder.jp/contests/abc032/tasks/abc032_d
 * Result: AC
 * Execution Time: 333 ms
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
    
    ll N,W; input(N,W);
    vector<ll> v(N),w(N);
    ll max_w = 0;
    rep(i,N){
        input(v[i],w[i]);
        max_w = max(max_w,w[i]);
    }

    if(N <= 30){
        // 半分全列挙
        ll ans = 0;
        vector<P> c1,c2;
        for(ll i=0;i<(1LL << (N/2));i++){
            ll now_w = 0, now_v = 0;
            rep(j,N/2){
                if(i & (1LL << j)){
                    now_w += w[j];
                    now_v += v[j];
                }
            }
            c1.push_back(P(now_w,now_v));
        }
        for(ll i=0;i<(1LL << (N-N/2));i++){
            ll now_w = 0, now_v = 0;
            rep(j,N-N/2){
                if(i & (1LL << j)){
                    now_w += w[j+N/2];
                    now_v += v[j+N/2];
                }
            }
            c2.push_back(P(now_w,now_v));
        }
        sort(c1.begin(),c1.end());
        sort(c2.begin(),c2.end());

        vector<P> c3,c4;
        ll mw = 0,mv = 0;
        rep(i,c1.size()){
            auto &&[nw,nv] = c1[i];
            if(mw != nw){
                c3.emplace_back(P(mw,mv));
            }
            mw = nw;
            mv = max(mv,nv);
        }
        c3.emplace_back(P(mw,mv));
        mw = 0,mv = 0;
        rep(i,c2.size()){
            auto [nw,nv] = c2[i];
            if(mw != nw){
                c4.emplace_back(P(mw,mv));
            }
            mw = nw;
            mv = max(mv,nv);
        }
        c4.emplace_back(P(mw,mv));

        for(auto [nw,nv]:c3){
            if(nw > W)continue;
            auto itr = upper_bound(c4.begin(),c4.end(),P(W-nw,LLONG_MAX));
            itr--;
            auto [tw,tv] = *itr;
            ans = max(ans,nv+tv);
        }
        print(ans);
    }
    else if(max_w <= 1000){
        // ナップサック(横軸：重さ)
        vector<vector<ll>> dp(N+1,vector<ll>(N*1000+1,-1));
        dp[0][0] = 0;
        rep(i,N){
            rep(j,N*1000+1){
                if(dp[i][j] == -1)continue;
                dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
                if(j+w[i] <= N*1000)dp[i+1][j+w[i]] = max(dp[i+1][j+w[i]],dp[i][j]+v[i]);
            }
        }
        ll ans = 0;
        rep(i,W+1)ans = max(ans,dp[N][i]);
        print(ans);
    }
    else{
        // ナップサック(横軸：価値)
        vector<vector<ll>> dp(N+1,vector<ll>(N*1000+1,1e18));
        dp[0][0] = 0;
        rep(i,N){
            rep(j,N*1000+1){
                dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
                if(j+v[i] <= N*1000)dp[i+1][j+v[i]] = min(dp[i+1][j+v[i]],dp[i][j]+w[i]);
            }
        }
        ll ans = 0;
        rep(i,N*1000+1)if(dp[N][i] <= W)ans = max(ans,i);
        print(ans);
    }
    
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc147/submissions/34619214
 * Submitted at: 2022-09-04 22:50:02
 * Problem URL: https://atcoder.jp/contests/arc147/tasks/arc147_c
 * Result: AC
 * Execution Time: 179 ms
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
typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    vector<P> range;
    rep(i,n){
        ll l,r; input(l,r);
        range.push_back(P(l,r));
    }
    
    //境界を決めてスコアを出せば極値1つで三部探索出来そう…？
    ll left = 1,right = 10000001;
    while(right-left > 2){
        ll m1 = (left+left+right)/3,m2 = (left+right+right)/3;
        ll s1 = 0,s2 = 0;
        rep(i,n){
            auto [l,r] = range[i];
            if( m1 < l || m1 > r )s1 += min(abs(m1-l),abs(m1-r));
            if( m2 < l || m2 > r )s2 += min(abs(m2-l),abs(m2-r));
        }
        if(s1 >= s2)left = m1;
        else right = m2;
    }
    
    vector<vector<ll>> ans;
    for(ll i=left;i<=right;i++){
        vector<ll> cand;
        cand.push_back(0);
        ll tmp = 0;
        rep(j,n){
            auto [l,r] = range[j];
            if( l <= i && i <= r )cand.push_back(i);
            else cand.push_back((abs(l-i) <= abs(r-i) ? l : r));
        }
        sort(cand.begin(),cand.end());
        ans.push_back(cand);
    }

    //累積和で答えを求めるpart
    rep(i,3)rep(j,n)ans[i][j+1] += ans[i][j];
    ll answer = LLONG_MAX;
    rep(i,3){
        ll tmp = 0;
        for(ll j=1;j<=n;j++){
            tmp += (ans[i][j]-ans[i][j-1])*(j-1)-(ans[i][j-1]) + (ans[i].back()-ans[i][j])-(ans[i][j]-ans[i][j-1])*(n-j);
        }
        answer = min(answer,tmp);
    }
    print(answer/2);
    
    return 0;
}
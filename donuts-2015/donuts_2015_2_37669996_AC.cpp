/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/donuts-2015/submissions/37669996
 * Submitted at: 2023-01-01 12:31:48
 * Problem URL: https://atcoder.jp/contests/donuts-2015/tasks/donuts_2015_2
 * Result: AC
 * Execution Time: 24 ms
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
    
    ll n,m; input(n,m);
    vector<ll> p(n);
    rep(i,n)input(p[i]);

    vector<ll> bonus(m);
    vector member(m,vector<ll>{});
    rep(i,m){
        ll b,c; input(b,c);
        bonus[i] = b;
        rep(j,c){
            ll mem; input(mem); mem--;
            member[i].push_back(mem);
        }
    }

    ll ans = 0;
    rep(i,(1LL << n)){
        ll point = 0,cnt = 0;
        vector<bool> idol(n,false);
        rep(j,n){
            if(i & (1LL << j)){
                idol[j] = true;
                point += p[j];
                cnt++;
            }
        }
        if(cnt != 9)continue;
        rep(j,m){
            ll combo = 0;
            for(ll mem:member[j])combo += idol[mem];
            if(combo >= 3)point += bonus[j];
        }
        ans = max(ans,point);
    }
    print(ans);
    
    return 0;
}
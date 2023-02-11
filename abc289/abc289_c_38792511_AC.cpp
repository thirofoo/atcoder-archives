/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc289/submissions/38792511
 * Submitted at: 2023-02-11 21:19:10
 * Problem URL: https://atcoder.jp/contests/abc289/tasks/abc289_c
 * Result: AC
 * Execution Time: 8 ms
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
    vector<ll> cc;
    vector<vector<ll>> num(m);
    rep(i,m){
        ll c; input(c);
        cc.push_back(c);
        rep(j,c){
            ll a; input(a);
            num[i].push_back(a);
        }
    }

    ll answer = 0;
    for(ll i=0;i<(1LL << m);i++){
        vector<bool> used(n,false);
        rep(j,m){
            if(i & (1LL << j)){
                for(ll k=0;k<cc[j];k++){
                    used[num[j][k]-1] = true;
                }
            }
        }
        bool ans = true;
        rep(j,n){
            ans &= used[j];
        }
        if(ans)answer++;
    }
    print(answer);
    
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc295/submissions/40028428
 * Submitted at: 2023-03-25 21:09:09
 * Problem URL: https://atcoder.jp/contests/abc295/tasks/abc295_b
 * Result: AC
 * Execution Time: 16 ms
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
    
    ll r,c; input(r,c);
    vector<string> f(r),ans(r);
    rep(i,r)input(f[i]);
    ans = f;

    rep(i,r){
        rep(j,c){
            if('1' <= f[i][j] && f[i][j] <= '9'){
                ll num = f[i][j]-'0';
                for(ll h=i-num;h<=i+num;h++){
                    for(ll w=j-num;w<=j+num;w++){
                        if(h < 0 || h >= r || w < 0 || w >= c)continue;
                        if(abs(i-h) + abs(j-w) > num)continue;
                        ans[h][w] = '.';
                    }
                }
            }
        }
    }
    rep(i,r)print(ans[i]);
    
    return 0;
}
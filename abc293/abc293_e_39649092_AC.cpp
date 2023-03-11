/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc293/submissions/39649092
 * Submitted at: 2023-03-12 00:38:33
 * Problem URL: https://atcoder.jp/contests/abc293/tasks/abc293_e
 * Result: AC
 * Execution Time: 6 ms
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
    
    // 等比級数の和より、前までの項の総和+1が次の項
    // → a_{n+1} = A*a{n}+1
    // → { a_{n+1},1 } = { {A,1},{0,1} } * {a_{n},1}
    // → 行列の繰り返し二乗法
    ll a,x,m; input(a,x,m);
    vector r(60,vector<vector<ll>>(2,vector<ll>(2,0)));
    r[0] = { {a%m,1},{0,1} };
    for(ll i=1;i<60;i++){
        rep(j,2)rep(l,2){
            r[i][j][l] = (r[i-1][j][0]*r[i-1][0][l] + r[i-1][j][1]*r[i-1][1][l])%m;
        }
    }
    vector now(2,vector<ll>(2,1));
    now[0][1] = 0,now[1][0] = 0;
    rep(i,60){
        vector next(2,vector<ll>(2,1));
        if(x & (1LL << i)){
            rep(j,2)rep(l,2){
                next[j][l] = (now[j][0]*r[i][0][l] + now[j][1]*r[i][1][l])%m;
            }
            swap(now,next);
        }
    }
    print(now[0][1]%m);
    
    return 0;
}
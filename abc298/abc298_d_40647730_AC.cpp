/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc298/submissions/40647730
 * Submitted at: 2023-04-15 21:21:13
 * Problem URL: https://atcoder.jp/contests/abc298/tasks/abc298_d
 * Result: AC
 * Execution Time: 72 ms
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
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll q; input(q);
    queue<ll> num;
    num.push(1);
    mint ans = 1;

    vector<mint> r(q+1,1);
    rep(i,q)r[i+1] = r[i]*10;

    while(q--){
        ll t; input(t);
        if(t == 1){
            ll x; input(x);
            num.push(x);
            ans *= 10;
            ans += x;
        }
        else if(t == 2){
            ans -= r[num.size()-1]*num.front();
            num.pop();
        }
        else{
            print(ans.val());
        }
    }
    
    return 0;
}
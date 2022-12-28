/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc096/submissions/37595226
 * Submitted at: 2022-12-28 16:33:28
 * Problem URL: https://atcoder.jp/contests/abc096/tasks/abc096_d
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

vector<bool> flags;
void eratosthenes(ll n){
    flags.assign(n,true);
    flags[0] = false; flags[1] = false;
    const ll sqrt_n = ceil(sqrt(n)+0.1);
    for(ll i = 2; i < sqrt_n; i++){
        if(!flags[i])continue;
        for(ll j = i*i; j < n; j += i){
            flags[j] = false;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    eratosthenes(55556);
    ll tmp = 0;
    for(ll i=2;i<=55555;i++){
        if(flags[i] && i%5 == 1){
            cout << i << " ";
            n--;
        }
        if(!n)break;
    }
    print();
    
    return 0;
}
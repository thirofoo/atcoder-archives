/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc164/submissions/43419221
 * Submitted at: 2023-07-09 21:09:29
 * Problem URL: https://atcoder.jp/contests/arc164/tasks/arc164_a
 * Result: AC
 * Execution Time: 60 ms
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
    
    ll t; input(t);
    while(t--){
        ll n,k; input(n,k);
        if( k > n ){
            print("No");
            continue;
        }
        unsigned long long r = 1;
        while(r <= n)r *= 3;
        while(k){
            if( r > n )r /= 3;
            else{
                n -= r;
                k--;
            }
            if( n == 0 )break;
        }
        print( ( (n == 0 && k%2 == 0) ? "Yes" : "No") );
    }
    
    return 0;
}



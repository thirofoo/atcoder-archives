/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc284/submissions/37810261
 * Submitted at: 2023-01-07 21:14:09
 * Problem URL: https://atcoder.jp/contests/abc284/tasks/abc284_d
 * Result: AC
 * Execution Time: 184 ms
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
        ll n,cnt = 0,a1 = -1,a2 = -1; input(n);
        for(ll i=2;i*i*i<=n;i++){
            if(n%i == 0){
                if((n/i)%i == 0)a1 = i;
                else a2 = i;
            }
        }
        if(a1 == -1){
            a1 = sqrt(n/a2);
        }
        else{
            a2 = n/a1/a1;
        }
        print(a1,a2);
    }
    
    return 0;
}
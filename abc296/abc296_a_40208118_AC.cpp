/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc296/submissions/40208118
 * Submitted at: 2023-04-01 21:01:45
 * Problem URL: https://atcoder.jp/contests/abc296/tasks/abc296_a
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
    
    ll n; string s; input(n,s);
    if(s[0] == 'M'){
        rep(i,n){
            if(i%2 == 0){
                if(s[i] != 'M')return print("No"),0;
            }
            else{
                if(s[i] != 'F')return print("No"),0;
            }
        }
    }
    else{
        rep(i,n){
            if(i%2 == 0){
                if(s[i] != 'F')return print("No"),0;
            }
            else{
                if(s[i] != 'M')return print("No"),0;
            }
        }
    }
    print("Yes");
    
    return 0;
}
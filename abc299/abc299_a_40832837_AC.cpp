/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc299/submissions/40832837
 * Submitted at: 2023-04-22 21:05:04
 * Problem URL: https://atcoder.jp/contests/abc299/tasks/abc299_a
 * Result: AC
 * Execution Time: 7 ms
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
    bool f = false;
    rep(i,n){
        if(s[i] == '|'){
            f = !f;
        }
        else if(s[i] == '*'){
            if(f){
                print("in");
                return 0;
            }
        }
    }
    print("out");
    
    return 0;
}
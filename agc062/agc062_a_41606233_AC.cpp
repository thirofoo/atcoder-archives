/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc062/submissions/41606233
 * Submitted at: 2023-05-21 21:21:29
 * Problem URL: https://atcoder.jp/contests/agc062/tasks/agc062_a
 * Result: AC
 * Execution Time: 12 ms
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
        ll n; string s; input(n,s);
        bool f1 = true, f2 = false;
        rep(i,n){
            if(s[i] == 'B')f1 = false;
            if(i != n-1 && (s[i] == 'B' && s[i+1] == 'A')){
                f2 = true;
                break;
            }
        }
        if(f1 || f2)print("A");
        else print("B");
    }
    
    return 0;
}
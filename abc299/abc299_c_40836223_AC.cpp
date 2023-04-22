/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc299/submissions/40836223
 * Submitted at: 2023-04-22 21:08:56
 * Problem URL: https://atcoder.jp/contests/abc299/tasks/abc299_c
 * Result: AC
 * Execution Time: 21 ms
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
    ll ans = 0,cnt = 0;
    rep(i,n){
        if(s[i] == '-'){
            f = true;
            ans = max(ans,cnt);
            cnt = 0;
        }
        else{
            cnt++;
        }
    }
    if(f)ans = max(ans,cnt);

    if(ans == 0)print(-1);
    else print(ans);
    
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc282/submissions/37329779
 * Submitted at: 2022-12-17 21:07:11
 * Problem URL: https://atcoder.jp/contests/abc282/tasks/abc282_c
 * Result: AC
 * Execution Time: 10 ms
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
    string ans = "";
    ll cnt = 0;
    rep(i,n){
        if('a' <= s[i] && s[i] <= 'z')ans += s[i];
        else if(s[i] == '"'){
            ans += s[i];
            cnt++;
        }
        else{
            if(cnt%2 == 0)ans += '.';
            else ans += ',';
        }
    }
    print(ans);
    
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc297/submissions/40460672
 * Submitted at: 2023-04-09 21:09:47
 * Problem URL: https://atcoder.jp/contests/abc297/tasks/abc297_c
 * Result: AC
 * Execution Time: 8 ms
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
    
    ll h,w; input(h,w);
    vector<string> s(h);
    rep(i,h)input(s[i]);
    rep(i,h){
        bool f = true;
        ll cnt = 0;
        rep(j,w-1){
            if(s[i][j] == 'T' && s[i][j+1] == 'T'){
                s[i][j] = 'P';
                s[i][j+1] = 'C';
            }
        }
    }
    rep(i,h)print(s[i]);
    
    return 0;
}
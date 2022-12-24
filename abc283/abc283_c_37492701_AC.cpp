/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc283/submissions/37492701
 * Submitted at: 2022-12-24 21:08:20
 * Problem URL: https://atcoder.jp/contests/abc283/tasks/abc283_c
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
typedef pair<char, ll> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string s; input(s);
    vector<P> cnt;
    char now = s[0];
    ll tmp = 0;
    rep(i,s.size()){
        if(now == s[i])tmp++;
        else {
            cnt.push_back(P(now,tmp));
            now = s[i];
            tmp = 1;
        }
    }
    cnt.push_back(P(now,tmp));
    ll ans = 0;
    for(auto [ch,t]:cnt){
        if(ch == '0')ans += t/2 + t%2;
        else ans += t;
    }
    print(ans);
    
    return 0;
}
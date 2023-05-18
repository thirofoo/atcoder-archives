/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc037/submissions/41496010
 * Submitted at: 2023-05-18 19:02:59
 * Problem URL: https://atcoder.jp/contests/agc037/tasks/agc037_a
 * Result: AC
 * Execution Time: 13 ms
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
    
    string s; input(s);
    string now = "", pre = "";
    ll ans = 0;
    rep(i,s.size()){
        now += s[i];
        if(pre != now){
            pre = now;
            now = "";
            ans++;
        }
    }
    print(ans);
    
    return 0;
}
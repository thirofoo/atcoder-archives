/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc192/submissions/38133649
 * Submitted at: 2023-01-18 17:34:28
 * Problem URL: https://atcoder.jp/contests/abc192/tasks/abc192_c
 * Result: AC
 * Execution Time: 38 ms
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
    
    string s; ll k; input(s,k);
    rep(i,k){
        string s1 = s,s2 = s;
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end(),[](char c1 ,char c2){
            return c1 > c2;
        });
        s = to_string(stoll(s2)-stoll(s1));
    }
    print(s);
    
    return 0;
}
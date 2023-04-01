/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc296/submissions/40214047
 * Submitted at: 2023-04-01 21:06:00
 * Problem URL: https://atcoder.jp/contests/abc296/tasks/abc296_b
 * Result: WA
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
    
    vector<string> s(8);
    rep(i,8)input(s[i]);
    string ans = "";
    for(int i=7;i>=0;i--){
        rep(j,7){
            if(s[i][j] == '*'){
                ans += 'a'+j;
                ans += '1'+7-i;
            }
        }
    }
    print(ans);
    
    return 0;
}
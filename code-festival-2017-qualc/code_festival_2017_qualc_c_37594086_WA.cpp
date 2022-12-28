/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/code-festival-2017-qualc/submissions/37594086
 * Submitted at: 2022-12-28 15:32:00
 * Problem URL: https://atcoder.jp/contests/code-festival-2017-qualc/tasks/code_festival_2017_qualc_c
 * Result: WA
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
    
    string s; input(s);
    ll l = 0,r = s.size()-1,ans = 0;
    while(l <= r){
        if((s[l] == 'a' && s[r] == 'b') || (s[l] == 'a' && s[r] == 'b'))return print(-1),0;
        if(s[l] == s[r]){
            l++;
            r--;
        }
        else{
            if(s[l] == 'x')l++;
            else r--;
            ans++;
        }
    }
    print(ans);
    
    return 0;
}
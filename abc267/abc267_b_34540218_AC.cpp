/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc267/submissions/34540218
 * Submitted at: 2022-09-03 21:12:14
 * Problem URL: https://atcoder.jp/contests/abc267/tasks/abc267_b
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
typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string s; input(s);
    if(s[0] == '1')return print("No"),0;
    vector<bool> f(7,false);
    f[0] = (s[6] == '1');
    f[1] = (s[3] == '1');
    f[2] = (s[7] == '1' || s[1] == '1');
    f[3] = (s[4] == '1');
    f[4] = (s[8] == '1' || s[2] == '1');
    f[5] = (s[5] == '1');
    f[6] = (s[9] == '1');
    bool f1 = false,f2 = false,f3 = false;
    rep(i,7){
        if(f2 && f[i])return print("Yes"),0;
        if(f1 && !f[i])f2 = true;
        if(!f1 && f[i])f1 = true;
    }
    print("No");
    
    return 0;
}
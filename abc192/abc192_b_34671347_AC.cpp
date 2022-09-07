/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc192/submissions/34671347
 * Submitted at: 2022-09-07 18:13:52
 * Problem URL: https://atcoder.jp/contests/abc192/tasks/abc192_b
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
    
    string s; input(s);
    for(int i=0;i<s.size();i++){
        if(i%2 == 0 && s[i] <= 'Z')return print("No"),0;
        else if(i%2 == 1 && s[i] > 'Z')return print("No"),0;
    }
    print("Yes");
    
    return 0;
}
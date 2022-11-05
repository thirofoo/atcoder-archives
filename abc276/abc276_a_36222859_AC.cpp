/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc276/submissions/36222859
 * Submitted at: 2022-11-05 21:01:47
 * Problem URL: https://atcoder.jp/contests/abc276/tasks/abc276_a
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
    reverse(s.begin(),s.end());
    rep(i,s.size()){
        if(s[i] == 'a'){
            return print(s.size()-i),0;
        }
    }
    print(-1);
    
    return 0;
}
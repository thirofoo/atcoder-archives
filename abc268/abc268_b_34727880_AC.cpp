/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc268/submissions/34727880
 * Submitted at: 2022-09-10 21:02:21
 * Problem URL: https://atcoder.jp/contests/abc268/tasks/abc268_b
 * Result: AC
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
    
    string s,t; input(s,t);
    if(s.size() > t.size())print("No");
    else{
        ll size = s.size();
        rep(i,size){
            if(s[i] == t[i])continue;
            return print("No"),0;
        }
        print("Yes");
    }
    
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc279/submissions/36799037
 * Submitted at: 2022-11-26 21:05:26
 * Problem URL: https://atcoder.jp/contests/abc279/tasks/abc279_b
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
    
    string s,t; input(s,t);
    rep(i,s.size()){
        string tmp = "";
        for(int j=i;j<i+t.size();j++){
            if(j >= s.size())break;
            tmp += s[j];
        }
        if(t == tmp)return print("Yes"),0;
    }
    print("No");
    
    return 0;
}
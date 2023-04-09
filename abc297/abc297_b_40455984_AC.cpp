/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc297/submissions/40455984
 * Submitted at: 2023-04-09 21:04:48
 * Problem URL: https://atcoder.jp/contests/abc297/tasks/abc297_b
 * Result: AC
 * Execution Time: 6 ms
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
    vector<ll> i1,i2,i3;
    rep(i,s.size()){
        if(s[i] == 'B')i1.push_back(i);
        if(s[i] == 'R')i2.push_back(i);
        if(s[i] == 'K')i3.push_back(i);
    }
    if(i1[0]%2 == i1[1]%2){
        print("No");
        return 0;
    }
    if(i2[0] < i3[0] && i3[0] < i2[1]){
        print("Yes");
    }
    else print("No");
    
    return 0;
}
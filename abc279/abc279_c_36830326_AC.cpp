/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc279/submissions/36830326
 * Submitted at: 2022-11-26 23:11:50
 * Problem URL: https://atcoder.jp/contests/abc279/tasks/abc279_c
 * Result: AC
 * Execution Time: 62 ms
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
    
    ll h,w; input(h,w);
    vector<string> s(h),t(h);
    rep(i,h)input(s[i]);
    rep(i,h)input(t[i]);
    map<string,int> ss,tt;
    rep(j,w){
        string tmp = "";
        rep(i,h)tmp += s[i][j];
        ss[tmp]++;
        // print(tmp);
    }
    rep(j,w){
        string tmp = "";
        rep(i,h)tmp += t[i][j];
        tt[tmp]++;
        // print(tmp);
    }
    for(auto [str,num]:ss){
        if(!tt[str])return print("No"),0;
        if(tt[str] != num)return print("No"),0;
    }
    print("Yes");
    
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc301/submissions/41355518
 * Submitted at: 2023-05-13 21:14:05
 * Problem URL: https://atcoder.jp/contests/abc301/tasks/abc301_c
 * Result: AC
 * Execution Time: 10 ms
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

vector<char> ch = {'a','t','c','o','d','e','r'};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string s,t; input(s,t);
    vector<ll> c1(26,0),c2(26,0);
    ll ok = 0;
    rep(i,s.size()){
        if(s[i] != '@')c1[s[i]-'a']++;
        else ok++;
    }
    rep(i,t.size()){
        if(t[i] != '@')c2[t[i]-'a']++;
        else ok++;
    }
    rep(i,26){
        bool f = false;
        rep(j,7)if(ch[j]-'a' == i)f = true;
        if(!f && abs(c1[i]-c2[i]) > 0)return print("No"),0;
        ok -= abs(c1[i]-c2[i]);
    }
    if(ok >= 0)print("Yes");
    else print("No");
    
    return 0;
}
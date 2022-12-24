/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc283/submissions/37500420
 * Submitted at: 2022-12-24 21:20:58
 * Problem URL: https://atcoder.jp/contests/abc283/tasks/abc283_d
 * Result: AC
 * Execution Time: 40 ms
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

ll idx = 0,z;
bool f = true;
void dfs(string &s){
    vector<ll> cnt(26,0);
    while(idx != z){
        if(s[idx] == ')'){
            idx++;
            dfs(s);
        }
        else {
            if('a' <= s[idx] && s[idx] <= 'z')cnt[s[idx]-'a']++;
            idx++;
        }
    }
    rep(i,26)f &= (cnt[i] <= 1);
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string s; input(s);
    z = s.size();
    dfs(s);
    print(f ? "Yes" : "No");
    
    return 0;
}
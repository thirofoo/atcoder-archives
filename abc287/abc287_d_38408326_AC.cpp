/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc287/submissions/38408326
 * Submitted at: 2023-01-28 21:52:49
 * Problem URL: https://atcoder.jp/contests/abc287/tasks/abc287_d
 * Result: AC
 * Execution Time: 25 ms
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
    vector<bool> ok1(s.size()+1,false),ok2(s.size()+1,false);
    bool f1 = true;
    rep(i,t.size()){
        if(s[i] != '?' && t[i] != '?' && s[i] != t[i])f1 = false;
        if(!f1)break;
        ok1[i] = true;
    }

    bool f2 = true;
    rep(i,t.size()){
        if(s[s.size()-i-1] != '?' && t[t.size()-i-1] != '?' && s[s.size()-i-1] != t[t.size()-i-1])f2 = false;
        if(!f2)break;
        ok2[s.size()-i] = true;
    }

    print(ok2[s.size()-t.size()+1] ? "Yes" : "No");
    rep(i,t.size()-1)print((ok1[i] && ok2[s.size()-t.size()+1+1+i]) ? "Yes" : "No");
    print(ok1[t.size()-1] ? "Yes" : "No");
    
    return 0;
}
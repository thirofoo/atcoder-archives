/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc287/submissions/38381709
 * Submitted at: 2023-01-28 21:05:02
 * Problem URL: https://atcoder.jp/contests/abc287/tasks/abc287_b
 * Result: AC
 * Execution Time: 27 ms
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
    
    ll n,m; input(n,m);
    vector<string> s1(n);
    set<string> st;
    rep(i,n)input(s1[i]);
    rep(i,m){
        string t; input(t);
        st.insert(t);
    }
    ll ans = 0;
    rep(i,n){
        string tmp = "";
        tmp += s1[i][3];
        tmp += s1[i][4];
        tmp += s1[i][5];
        for(auto t:st){
            if(tmp == t)ans++;
        }
    }
    print(ans);
    
    return 0;
}
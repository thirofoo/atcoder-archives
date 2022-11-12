/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc277/submissions/36416111
 * Submitted at: 2022-11-12 21:10:25
 * Problem URL: https://atcoder.jp/contests/abc277/tasks/abc277_b
 * Result: AC
 * Execution Time: 16 ms
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

vector<char> o = {'H','D','C','S'};
vector<char> t = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    set<string> st;
    rep(i,n){
        string s; input(s);
        if(st.count(s))return print("No"),0;
        st.insert(s);
        bool f1 = true,f2 = true;
        rep(j,4)if(s[0] == o[j])f1 = false;
        rep(j,13)if(s[1] == t[j])f2 = false;
        if(f1 || f2)return print("No"),0;
    }
    print("Yes");
    
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc291/submissions/39231753
 * Submitted at: 2023-02-26 21:05:44
 * Problem URL: https://atcoder.jp/contests/abc291/tasks/abc291_c
 * Result: AC
 * Execution Time: 82 ms
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
    
    ll n; string s; input(n,s);
    bool f = false;
    set<P> st;
    st.insert(P(0,0));
    ll x = 0, y = 0;
    rep(i,n){
        if(s[i] == 'L')y--;
        else if(s[i] == 'R')y++;
        else if(s[i] == 'D')x--;
        else x++;
        if(st.count(P(x,y))){
            print("Yes");
            return 0;
        }
        st.insert(P(x,y));
    }
    print("No");
    
    return 0;
}
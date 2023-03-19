/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc294/submissions/39852755
 * Submitted at: 2023-03-19 21:11:12
 * Problem URL: https://atcoder.jp/contests/abc294/tasks/abc294_d
 * Result: AC
 * Execution Time: 173 ms
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
    
    ll n,q; input(n,q);
    set<ll> st;
    priority_queue<ll,vector<ll>,greater<ll>> todo;
    ll now = 1;
    while(q--){
        ll t; input(t);
        if(t == 1){
            todo.push(now);
            now++;
        }
        else if(t == 2){
            ll x; input(x);
            st.insert(x);
        }
        else{
            while(st.count(todo.top()))todo.pop();
            print(todo.top());
        }
    }
    
    return 0;
}
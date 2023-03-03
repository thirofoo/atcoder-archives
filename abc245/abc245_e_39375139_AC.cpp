/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc245/submissions/39375139
 * Submitted at: 2023-03-03 19:58:28
 * Problem URL: https://atcoder.jp/contests/abc245/tasks/abc245_e
 * Result: AC
 * Execution Time: 206 ms
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
    priority_queue<T> todo;
    vector<ll> h1(n),w1(n),h2(m),w2(m);
    rep(i,n)input(h1[i]);
    rep(i,n)input(w1[i]);
    rep(i,m)input(h2[i]);
    rep(i,m)input(w2[i]);
    rep(i,n)todo.push(T(h1[i],w1[i],0));
    rep(i,m)todo.push(T(h2[i],w2[i],1));
    multiset<ll> st;
    while(!todo.empty()){
        auto [h,w,i] = todo.top(); todo.pop();
        if(i == 0){
            auto itr = st.lower_bound(w);
            if(itr == st.end())return print("No"),0;
            st.erase(itr);
        }
        else st.insert(w);
    }
    print("Yes");
    
    return 0;
}
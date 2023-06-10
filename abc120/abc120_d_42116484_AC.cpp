/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc120/submissions/42116484
 * Submitted at: 2023-06-10 18:36:21
 * Problem URL: https://atcoder.jp/contests/abc120/tasks/abc120_d
 * Result: AC
 * Execution Time: 36 ms
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
    stack<ll> ans;
    stack<P> st;
    rep(i,m){
        ll a,b; input(a,b);
        a--; b--;
        st.push(P(a,b));
    }

    ll now = n*(n-1)/2;
    dsu uf(n);
    while(!st.empty()){
        ans.push( now );
        auto [a,b] = st.top(); st.pop();
        if(!uf.same(a,b))now -= uf.size(a) * uf.size(b);
        uf.merge(a,b);
    }
    while(!ans.empty()){
        print(ans.top());
        ans.pop();
    }
    
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc229/submissions/39290588
 * Submitted at: 2023-02-27 18:45:10
 * Problem URL: https://atcoder.jp/contests/abc229/tasks/abc229_e
 * Result: AC
 * Execution Time: 100 ms
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
    vector<vector<ll>> Graph(n);
    rep(i,m){
        ll a,b; input(a,b);
        a--; b--;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    dsu uf(n);
    ll num = 0;
    stack<ll> st;
    st.push(num);
    for(ll i=n-1;i>=1;i--){
        num++;
        for(auto ele:Graph[i]){
            if(ele < i)continue;
            if(uf.same(i,ele))continue;
            uf.merge(i,ele);
            num--;
        }
        st.push(num);
    }
    while(!st.empty()){
        print(st.top());
        st.pop();
    }
    
    return 0;
}
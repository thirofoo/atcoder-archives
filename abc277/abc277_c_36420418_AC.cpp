/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc277/submissions/36420418
 * Submitted at: 2022-11-12 21:17:22
 * Problem URL: https://atcoder.jp/contests/abc277/tasks/abc277_c
 * Result: AC
 * Execution Time: 408 ms
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
    
    ll n; input(n);
    map<int,vector<int>> m;
    rep(i,n){
        ll a,b; input(a,b);
        m[a].push_back(b);
        m[b].push_back(a);
    }
    ll ans = 1;
    queue<ll> todo;
    set<ll> st;
    todo.push(1);
    while(!todo.empty()){
        ll now = todo.front(); todo.pop();
        if(st.count(now))continue;
        st.insert(now);
        ans = max(ans,now);
        for(auto to:m[now])todo.push(to);
    }
    print(ans);
    
    return 0;
}
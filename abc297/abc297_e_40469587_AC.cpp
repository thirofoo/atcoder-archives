/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc297/submissions/40469587
 * Submitted at: 2023-04-09 21:21:31
 * Problem URL: https://atcoder.jp/contests/abc297/tasks/abc297_e
 * Result: AC
 * Execution Time: 522 ms
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
    
    ll n,k; input(n,k);
    vector<ll> a(n);
    priority_queue<ll,vector<ll>,greater<ll>> todo;
    rep(i,n){
        input(a[i]);
        todo.push(a[i]);
    }
    ll cnt = 0, ans;
    set<ll> st;
    while(st.size() < k){
        ll now = todo.top(); todo.pop();
        if(st.count(now))continue;
        st.insert(now);
        rep(i,n){
            ll next = now + a[i];
            if(st.count(next))continue;
            todo.push(next);
        }
    }
    print(*st.rbegin());
    
    return 0;
}
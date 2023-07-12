/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc252/submissions/43500962
 * Submitted at: 2023-07-12 14:43:06
 * Problem URL: https://atcoder.jp/contests/abc252/tasks/abc252_f
 * Result: AC
 * Execution Time: 69 ms
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
    
    // 逆順で合成する問題に帰着
    ll n,l; input(n,l);
    priority_queue<ll,vector<ll>,greater<ll>> todo;
    ll total = 0;
    rep(i,n){
        ll a; input(a);
        todo.push(a);
        total += a;
    }
    if( total != l ) todo.push( l-total );
    ll ans = 0;
    while(todo.size() != 1){
        ll e1 = todo.top(); todo.pop();
        ll e2 = todo.top(); todo.pop();
        ans += e1 + e2;
        todo.push( e1+e2 );
    }
    print( ans );
    
    return 0;
}
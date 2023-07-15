/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc210/submissions/43571942
 * Submitted at: 2023-07-15 13:57:11
 * Problem URL: https://atcoder.jp/contests/abc210/tasks/abc210_e
 * Result: AC
 * Execution Time: 46 ms
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

inline long long GCD(long long a, long long b){
    // 負 or a == 0 で -1
    if( a <= 0 || b < 0 ) return -1;
    if( b != 0 ) return GCD(b,a%b);
    return a;
}

inline long long LCM(long long a, long long b){
    // 負 or overflow の時は -1
    if( a < 0 || b < 0 ) return -1;
    if( (a / GCD(a,b)) < 1e18 / b ) return -1;
    return a  / GCD(a,b) * b;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m; input(n,m);
    priority_queue<P,vector<P>,greater<P>> todo;
    rep(i,m){
        ll a,c; input(a,c);
        todo.push( P(c,a) );
    }

    ll ans = 0, now = n;
    
    while(!todo.empty()){
        auto [c,a] = todo.top(); todo.pop();
        ans += ( now - GCD(now,a) ) * c;
        now = GCD(now,a);
    }
    print( (now == 1 ? ans : -1) );
    
    return 0;
}
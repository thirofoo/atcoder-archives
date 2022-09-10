/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc268/submissions/34734878
 * Submitted at: 2022-09-10 21:09:40
 * Problem URL: https://atcoder.jp/contests/abc268/tasks/abc268_c
 * Result: TLE
 * Execution Time: 2205 ms
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
    deque<ll> p(n);
    rep(i,n)input(p[i]);
    ll ans = 0;
    rep(i,n){
        ll tmp = 0;
        rep(j,n){
            if(j == p[j] || j == ((p[j]-1)%n+n)%n || j == ((p[j]+1)%n+n)%n)tmp++;
        }
        ans = max(ans,tmp);
        p.push_back(p.front());
        p.pop_front();
    }
    print(ans);
    
    return 0;
}
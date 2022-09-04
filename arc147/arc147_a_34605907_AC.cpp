/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc147/submissions/34605907
 * Submitted at: 2022-09-04 21:10:44
 * Problem URL: https://atcoder.jp/contests/arc147/tasks/arc147_a
 * Result: AC
 * Execution Time: 204 ms
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
typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,mini = LLONG_MAX; input(n);
    priority_queue<ll> t;
    rep(i,n){
        ll a; input(a);
        t.push(a);
        mini = min(mini,a);
    }
    ll cnt = 0;
    while(t.size() != 1){
        ll tmp = t.top(); t.pop();
        tmp %= mini;
        if(tmp != 0){
            mini = min(mini,tmp);
            t.push(tmp);
        }
        cnt++;
    }
    print(cnt);
    
    return 0;
}
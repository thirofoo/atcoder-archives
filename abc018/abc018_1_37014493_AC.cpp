/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc018/submissions/37014493
 * Submitted at: 2022-12-04 16:59:07
 * Problem URL: https://atcoder.jp/contests/abc018/tasks/abc018_1
 * Result: AC
 * Execution Time: 8 ms
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
    
    ll a,b,c; input(a,b,c);
    priority_queue<ll,vector<ll>,greater<ll>> todo;
    todo.push(a);
    todo.push(b);
    todo.push(c);
    ll num = 3;
    map<ll,ll> mp;
    while(!todo.empty()){
        ll tmp = todo.top(); todo.pop();
        mp[tmp] = num;
        num--;
    }
    print(mp[a]);
    print(mp[b]);
    print(mp[c]);
    
    return 0;
}
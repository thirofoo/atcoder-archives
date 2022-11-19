/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc278/submissions/36600704
 * Submitted at: 2022-11-19 21:02:59
 * Problem URL: https://atcoder.jp/contests/abc278/tasks/abc278_a
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
    
    ll n,k; input(n,k);
    deque<ll> q;
    rep(i,n){
        ll tmp; input(tmp);
        q.push_back(tmp);
    }
    while(k--){
        q.pop_front();
        q.push_back(0);
    }
    while(!q.empty()){
        print(q.front());
        q.pop_front();
    }
    
    return 0;
}
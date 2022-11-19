/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc278/submissions/36616355
 * Submitted at: 2022-11-19 21:25:53
 * Problem URL: https://atcoder.jp/contests/abc278/tasks/abc278_d
 * Result: AC
 * Execution Time: 91 ms
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
    vector<ll> a(n);
    rep(i,n)input(a[i]);

    map<P,ll> mp;
    ll turn = 0;
    ll q,now = 0; input(q);
    while(q--){
        ll t; input(t);
        if(t == 1){
            ll x; input(x);
            turn++;
            now = x;
        }
        else if(t == 2){
            ll i,x; input(i,x); i--;
            mp[P(turn,i)] += x;

        }
        else{
            ll i; input(i); i--;
            if(turn == 0)print(a[i]+mp[P(turn,i)]);
            else print(now+mp[P(turn,i)]);
        }
    }
    
    return 0;
}
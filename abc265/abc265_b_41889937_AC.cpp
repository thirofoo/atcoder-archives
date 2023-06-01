/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc265/submissions/41889937
 * Submitted at: 2023-06-01 19:13:10
 * Problem URL: https://atcoder.jp/contests/abc265/tasks/abc265_b
 * Result: AC
 * Execution Time: 80 ms
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
    
    ll n,m,t; input(n,m,t);
    vector<ll> a(n-1);
    rep(i,n-1)input(a[i]);
    map<ll,ll> mp;
    rep(i,m){
        ll x,y; input(x,y);
        mp[x] = y;
    }
    ll now = 0;
    while(now != n-1){
        if(mp.count(now+1))t += mp[now+1];
        t -= a[now];
        if(t <= 0){
            print("No");
            return 0;
        }
        now++;
    }
    print("Yes");
    
    return 0;
}
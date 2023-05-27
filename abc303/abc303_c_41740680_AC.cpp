/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc303/submissions/41740680
 * Submitted at: 2023-05-27 21:18:42
 * Problem URL: https://atcoder.jp/contests/abc303/tasks/abc303_c
 * Result: AC
 * Execution Time: 193 ms
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
    
    ll n,m,h,k; input(n,m,h,k);
    string s; input(s);
    map<P,ll> item;
    map<P,ll> used;
    rep(i,m){
        ll x,y; input(x,y);
        item[P(x,y)]++;
    }

    ll x = 0, y = 0;
    rep(i,n){
        if(s[i] == 'R')x++;
        if(s[i] == 'L')x--;
        if(s[i] == 'U')y++;
        if(s[i] == 'D')y--;
        h--;
        if(!used.count(P(x,y)) && item.count(P(x,y)) && h < k){
            h = k;
            used[P(x,y)]++;
        }
        if(h == 0 && i != n-1)return print("No"),0;
    }
    print("Yes");
    
    return 0;
}
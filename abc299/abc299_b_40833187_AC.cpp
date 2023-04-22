/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc299/submissions/40833187
 * Submitted at: 2023-04-22 21:05:26
 * Problem URL: https://atcoder.jp/contests/abc299/tasks/abc299_b
 * Result: AC
 * Execution Time: 60 ms
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
    
    ll n,t; input(n,t);
    vector<ll> c(n),r(n);
    rep(i,n)input(c[i]);
    rep(i,n)input(r[i]);
    vector<P> t1,t2;
    rep(i,n){
        if(c[i] == t)t1.push_back(P(r[i],i+1));
        else if(c[i] == c[0])t2.push_back(P(r[i],i+1));
    }
    sort(t1.begin(),t1.end());
    sort(t2.begin(),t2.end());
    if(t1.size() == 0){
        print(t2.back().second);
    }
    else print(t1.back().second);
    
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc308/submissions/43100642
 * Submitted at: 2023-07-01 21:11:21
 * Problem URL: https://atcoder.jp/contests/abc308/tasks/abc308_c
 * Result: WA
 * Execution Time: 78 ms
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
    vector<T> coin;
    rep(i,n){
        ll a,b; input(a,b);
        coin.push_back(T(a,b,i));
    }
    sort(coin.begin(),coin.end(),[](T &e1, T &e2){
        auto [a1,b1,i1] = e1;
        auto [a2,b2,i2] = e2;
        return a1*(a2+b2) > a2*(a1+b1);
    });
    rep(i,n){
        auto [a,b,idx] = coin[i];
        cout << idx+1 << " ";
    }
    print();
    
    return 0;
}
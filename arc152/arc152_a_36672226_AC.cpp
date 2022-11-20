/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc152/submissions/36672226
 * Submitted at: 2022-11-20 21:18:32
 * Problem URL: https://atcoder.jp/contests/arc152/tasks/arc152_a
 * Result: AC
 * Execution Time: 24 ms
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
    
    ll n,l; input(n,l);
    vector<ll> a(n);
    rep(i,n)input(a[i]);
    vector<bool> f(l,false);
    int idx = 0;
    rep(i,n){
        if(a[i] == 1){
            idx += 2;
        }
        else{
            if(idx >= l-1)return print("No"),0;
            else idx += 3;
        }
    }
    print("Yes");
    
    return 0;
}
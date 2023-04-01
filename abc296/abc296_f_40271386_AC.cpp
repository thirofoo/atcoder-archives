/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc296/submissions/40271386
 * Submitted at: 2023-04-01 23:41:29
 * Problem URL: https://atcoder.jp/contests/abc296/tasks/abc296_f
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
    
    // x解法 (完全嘘解法)
    // 3 4 5 6
    // 6 3 4 5


    ll n; input(n);
    vector<ll> a(n),b(n),cnt1(n+1,0),cnt2(n+1,0);
    vector<P> a1,b1;
    rep(i,n){
        input(a[i]);
        cnt1[a[i]]++;
    }
    rep(i,n){
        input(b[i]);
        cnt2[b[i]]++;
    }
    if(cnt1 != cnt2)return print("No"),0;
    rep(i,n)if(cnt1[i+1] >= 2)return print("Yes"),0;

    // 1 , 2 , 3
    // 3 , 2 , 1 は無理

    // 1 , 2 , 3
    // 3 , 1 , 2 はいける

    ll c1 = 0, c2 = 0;
    fenwick_tree<ll> fw1(n+1),fw2(n+1);
    rep(i,n){
        c1 += fw1.sum(0,a[i]);
        fw1.add(a[i],1);
        c2 += fw2.sum(0,b[i]);
        fw2.add(b[i],1);
    }
    print( c1%2 != c2%2 ? "No" : "Yes" );
    
    return 0;
}
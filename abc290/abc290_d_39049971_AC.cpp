/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc290/submissions/39049971
 * Submitted at: 2023-02-19 23:59:54
 * Problem URL: https://atcoder.jp/contests/abc290/tasks/abc290_d
 * Result: AC
 * Execution Time: 98 ms
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

ll euclid(ll a,ll b){
    if(b != 0)return euclid(b,a%b);
    else return a;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // k番目を配列のk番目と勘違い。悲しい。
    ll t; input(t);
    while(t--){
        ll n,d,k; input(n,d,k); k--;
        ll g = euclid(n,d);
        // 1周期ごとに全体的にインクリメントされるイメージ
        ll T = n/g;
        print( (d*(k%n))%n + k/T );
    }
    
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc276/submissions/38313660
 * Submitted at: 2023-01-25 14:41:24
 * Problem URL: https://atcoder.jp/contests/abc276/tasks/abc276_f
 * Result: AC
 * Execution Time: 84 ms
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
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    vector<ll> a(n);
    rep(i,n)input(a[i]);
    fenwick_tree<mint> fw1(2e5+5),fw2(2e5+5);

    mint ans = 0;
    rep(i,n){
        fw1.add(a[i],1);
        fw2.add(a[i],a[i]);
        ans = (ans*i*i + 2*(a[i]*fw1.sum(0,a[i]) + fw2.sum(a[i],2e5+5)) - a[i]) / (mint)( (i+1)*(i+1) );
        print(ans.val());
    }
    
    return 0;
}
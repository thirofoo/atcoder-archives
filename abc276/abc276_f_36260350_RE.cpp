/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc276/submissions/36260350
 * Submitted at: 2022-11-05 22:37:35
 * Problem URL: https://atcoder.jp/contests/abc276/tasks/abc276_f
 * Result: RE
 * Execution Time: 161 ms
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
    vector<ll> a(n),b(n+1,0);
    rep(i,n)input(a[i]);
    rep(i,n){
        b[i+1] = a[i];
        b[i+1] += b[i];
    }

    fenwick_tree<mint> fw1(200005),fw2(200005);
    print(a[0]);
    mint pre = a[0];
    for(int i=2;i<=n;i++){
        mint t1 = pre*(i-1)*(i-1)/i/i;
        mint t2 = 0;
        fw1.add(a[i-1],1);
        fw2.add(a[i-1],a[i-1]);
        mint num1 = fw1.sum(0,a[i-1]);
        mint num2 = fw2.sum(a[i-1]+1,200004);
        t2 += num1*a[i-1];
        t2 += (i-num1)*num2;
        t2 /= (i*i);
        print((t1+t2).val());
    }
    
    return 0;
}
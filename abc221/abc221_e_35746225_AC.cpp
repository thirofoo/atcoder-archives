/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc221/submissions/35746225
 * Submitted at: 2022-10-17 14:50:38
 * Problem URL: https://atcoder.jp/contests/abc221/tasks/abc221_e
 * Result: AC
 * Execution Time: 137 ms
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
    vector<ll> a(n),b;
    rep(i,n)input(a[i]);
    b = a;
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    rep(i,n)a[i] = lower_bound(b.begin(),b.end(),a[i])-b.begin();

    vector<mint> exp(n+1);
    exp[0] = 1,exp[1] = 2;
    for(int i=2;i<=n;i++)exp[i] = exp[i-1]*2;

    // fenwickを転倒数求める時っぽく用いる。
    mint ans = 0,tmp;
    fenwick_tree<mint> fw(n+1);
    fw.add(a[0],(mint)1/exp[0]);
    for(int i=1;i<n;i++){
        // 2^j-i-1 をjで全探索
        // iはjより左側∧a_j >= a_i を満たすもの。これの∑1/2^i を知りたい
        // => 1/2^iの逆元を保持したfenwickで総和を取る(O(NlogN))
        tmp = fw.sum(0,a[i]+1);
        tmp *= exp[i-1];
        fw.add(a[i],(mint)1/exp[i]);
        ans += tmp;
    }
    print(ans.val());

    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc220/submissions/42056101
 * Submitted at: 2023-06-07 17:25:37
 * Problem URL: https://atcoder.jp/contests/abc220/tasks/abc220_e
 * Result: AC
 * Execution Time: 29 ms
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
    
    ll n,d; input(n,d);
    vector<mint> r(2*n,1);
    for(ll i=1;i<2*n;i++)r[i] = r[i-1]*2;

    // 解説AC (天才過ぎ) ~~~ ある部分木の左側パスの長さxを全探索 ~~~
    // 左側候補：2^{x-1}
    // 右側候補：2^{d-x-1}
    // ↑を満たす部分木の根の候補：
    // l = max(x,d-x) とする
    // → 深さが N-1-l 以下の頂点が候補
    // → 2^{N-l}-1 個

    mint ans = 0;
    for(ll x=0;x<=d;x++){
        mint left = (x == 0 ? 1 : r[x-1]);
        mint right = (x == d ? 1 : r[d-x-1]);
        ll l = max(x,d-x);
        if(n-l >= 0)ans += left * right * (r[n-l]-1);
    }
    ans *= 2; // ペア入れ替え分
    print(ans.val());
    
    return 0;
}
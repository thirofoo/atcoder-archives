/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc167/submissions/36945965
 * Submitted at: 2022-12-03 19:49:34
 * Problem URL: https://atcoder.jp/contests/abc167/tasks/abc167_e
 * Result: AC
 * Execution Time: 54 ms
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
    
    ll n,m,k; input(n,m,k);
    mint ans = 0,tmp = 0;
    vector<mint> kaizyo(n+1),ruizyo(n+1);
    kaizyo[0] = 1;
    for(int i=1;i<=n;i++)kaizyo[i] = kaizyo[i-1]*i;
    ruizyo[0] = 1;
    for(int i=1;i<=n;i++)ruizyo[i] = ruizyo[i-1]*(m-1);

    rep(i,k+1){
        // ∑(m * n-1_C_i * 1^i * (m-1)^(n-1-i))
        ans += m * (kaizyo[n-1]/kaizyo[n-1-i]/kaizyo[i]) * ruizyo[n-1-i];
    }
    print(ans.val());
    
    return 0;
}
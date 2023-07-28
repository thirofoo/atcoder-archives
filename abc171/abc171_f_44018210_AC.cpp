/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc171/submissions/44018210
 * Submitted at: 2023-07-29 07:40:48
 * Problem URL: https://atcoder.jp/contests/abc171/tasks/abc171_f
 * Result: AC
 * Execution Time: 321 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説AC 二項定理の応用
    // 1. まず出来た N+K 文字の文字列に S が部分文字列として存在するものが題意を満たすと理解
    // 2. N+K 文字の文字列の i 文字目を考えた時、それがSの文字かそうでないかと考える
    // → Sの文字だった場合は 1 通り , そうでない場合は 25 通り
    // → ( x + 25 ) ^ { N+K } の x^n 以降の係数が今回の答え！
    // 3. 二項定理で展開
    // ※ 今回は x^? を Sの内 ? 文字を部分文字列として含む場合の数としている。天才。

    ll k, n; string s; cin >> k >> s;
    mint ans = 0;
    n = s.size();
    vector<mint> fact(n+k+1,1);
    vector<mint> r_fact(n+k+1,1);
    for(int i=1;i<=n+k;i++){
        fact[i] = fact[i-1]*i;
        r_fact[i] = (mint)1/fact[i];
    }
    auto nCr = [&](ll n,ll r){
        return fact[n] * r_fact[r] * r_fact[n-r];
    };
    mint r = 1;
    rep(i,k) r *= 25;

    for(int i=n;i<=n+k;i++){
        ans += nCr( n+k, i ) * r;
        r /= 25;
    }
    cout << ans.val() << endl;
    
    return 0;
}
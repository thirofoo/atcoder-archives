/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc172/submissions/35836506
 * Submitted at: 2022-10-21 21:57:28
 * Problem URL: https://atcoder.jp/contests/abc172/tasks/abc172_e
 * Result: AC
 * Execution Time: 167 ms
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
typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

mint nPr(int n,int r,vector<mint> &kaizyo){
    return kaizyo[n]/kaizyo[n-r];
}

mint nCr(int n,int r,vector<mint> &kaizyo){
    return kaizyo[n]/kaizyo[r]/kaizyo[n-r];
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m; input(n,m);
    vector<mint> con(n+1,0),kaizyo(m+1,0);
    kaizyo[0] = 1;
    for(int i=1;i<=m;i++)kaizyo[i] = kaizyo[i-1]*i;

    // Aをまず条件1を満たす様に固定化して考える。
    // ans = (重複無しのAの並べ方) *　(重複無しでAiとBi箇所以上一致するBの並べ方)
    //     = mPn * (重複無しのBの並べ方 - AiとBi箇所以上一致するBの並べ方)

    // Ai == Biがk箇所以上ある場合の数は nCk * m-kPn-k となる(一致する場所の組 * 残りの並べ方)
    // => これと包除原理を用いてAとBが1箇所以上一致する場合の数を求めてあげる
    
    // con[i] : i箇所以上でaとbが一致する場合の数
    for(int i=1;i<=n;i++)con[i] = nCr(n,i,kaizyo)*nPr(m-i,n-i,kaizyo);

    // いずれかのiにおいてa_i = b_i となる場合の数を求める
    mint ans = 0;
    for(int i=1;i<=n;i++)ans += con[i]*(i%2 == 1 ? 1 : -1);
    ans = (nPr(m,n,kaizyo)-ans)*nPr(m,n,kaizyo);
    print(ans.val());
    
    return 0;
}
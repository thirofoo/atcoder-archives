/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/42182968
 * Submitted at: 2023-06-11 13:53:22
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_r
 * Result: AC
 * Execution Time: 257 ms
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

using Matrix = vector<vector<ll>>;
Matrix matrix_multi(Matrix A, Matrix B, ll mod){
    // A * B の行列積
    ll s1 = A.size(), s2 = B.size(), s3 = B[0].size();
    Matrix mul(s1,vector<ll>(s3,0));
    for(int i=0;i<s1;i++){
        for(int j=0;j<s3;j++){
            for(int k=0;k<s2;k++){
                mul[i][j] += A[i][k]*B[k][j] % mod;
                mul[i][j] %= mod;
            }
        }
    }
    return mul;
}

Matrix matrix_pow(Matrix A, ll x, ll mod){
    Matrix res(A.size(),vector<ll>(A.size(),0));
    rep(i,A.size())res[i][i] = 1;

    Matrix r = A; // 行列累乗
    for(int i=0;i<=62;i++){
        if(x & (1LL << i))res = matrix_multi(res, r, mod);
        r = matrix_multi(r, r, mod);
    }
    return res;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,k; input(n,k);
    // まずは愚直にDPを考える
    // → 3次元dpが思いつくが、max(K) = 1e18 で余裕で死ぬ
    // → (n-1 → n) の遷移が固定であることに気づく
    ll mod = 1000000007;
    Matrix Graph(n,vector<ll>(n));
    rep(i,n)rep(j,n)input(Graph[i][j]);

    Matrix mat = matrix_pow(Graph, k, mod);
    ll ans = 0;
    rep(i,n)rep(j,n){
        ans += mat[i][j] % mod;
        ans %= mod;
    }
    print(ans);
    
    return 0;
}
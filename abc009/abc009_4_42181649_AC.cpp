/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc009/submissions/42181649
 * Submitted at: 2023-06-11 12:33:56
 * Problem URL: https://atcoder.jp/contests/abc009/tasks/abc009_4
 * Result: AC
 * Execution Time: 74 ms
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
Matrix matrix_multi(Matrix A, Matrix B){
    // A * B の行列積
    ll s1 = A.size(), s2 = B.size(), s3 = B[0].size();
    Matrix mul(s1,vector<ll>(s3,0));
    for(int i=0;i<s1;i++){
        for(int j=0;j<s3;j++){
            for(int k=0;k<s2;k++){
                mul[i][j] ^= A[i][k] & B[k][j];
            }
        }
    }
    return mul;
}

Matrix matrix_pow(Matrix A, ll x){
    Matrix res(A.size(),vector<ll>(A.size(),0));
    rep(i,A.size())res[i][i] = (1LL << 32) - 1;

    Matrix r = A; // 行列累乗
    for(int i=0;i<=62;i++){
        if(x & (1LL << i))res = matrix_multi(res, r);
        r = matrix_multi(r, r);
    }
    return res;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll k,m; input(k,m);
    Matrix a(k,vector<ll>(1)), c(k,vector<ll>(1));
    rep(i,k)input(a[k-i-1][0]);
    rep(i,k)input(c[i][0]);

    if(m == 1){
        print(a.back()[0]);
        return 0;
    }

    // 半環を満たす演算なら、足し算掛け算以外の演算ペアもOK!
    Matrix A(k,vector<ll>(k,0));
    rep(i,k)A[0][i] = c[i][0];
    // ここは元々は掛け算だったから、単位元の1だったが、ANDの場合は (1LL << 32) - 1 を入れる！
    rep(i,k-1)A[i+1][i] = (1LL << 32) - 1;

    Matrix ans = matrix_multi( matrix_pow(A, m-1), a );
    print( ans.back()[0] );
    
    return 0;
}
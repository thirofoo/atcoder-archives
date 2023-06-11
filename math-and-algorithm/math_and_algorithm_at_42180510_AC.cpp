/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/math-and-algorithm/submissions/42180510
 * Submitted at: 2023-06-11 11:29:15
 * Problem URL: https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_at
 * Result: AC
 * Execution Time: 7 ms
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
    
    ll n; input(n);
    ll mod = 1000000000ll;
    Matrix A = { {1, 1}, {1, 0} };
    print( matrix_multi(matrix_pow(A, n-1, mod), { {1}, {1} }, mod)[1][0] );
    
    return 0;
}
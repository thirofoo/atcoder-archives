/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/math-and-algorithm/submissions/42174361
 * Submitted at: 2023-06-11 01:15:45
 * Problem URL: https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_at
 * Result: AC
 * Execution Time: 5 ms
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
typedef modint mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

vector<vector<mint>> multi(vector<vector<mint>> A, vector<vector<mint>> B){
    // A * B の行列積
    ll s1 = A.size(), s2 = B.size(), s3 = B[0].size();
    vector<vector<mint>> mul(s1,vector<mint>(s3,0));
    rep(i,s1){
        rep(j,s3){
            rep(k,s2){
                mul[i][j] += A[i][k]*B[k][j];
            }
        }
    }
    return mul;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    // A_n = A_{n-1} + A_{n-2}
    // → { A_n, A_{n-1} } = A * { A_{n-1}, A_{n-2} }
    // と無理やり表現出来る → 行列累乗 (数列を行列に変換すれば何でも累乗出来る)
    ll mod = 1;
    rep(i,9)mod *= 10;
    mint::set_mod(mod);
    vector<vector<mint>> A = { {1,1}, {1,0} }, fib, ans;
    vector<vector<vector<mint>>> r;
    r.push_back(A);
    rep(i,62)r.push_back(multi(r.back(),r.back()));

    n--;
    fib = { {1, 0}, {0, 1} }; // 正則行列
    rep(i,62)if(n & (1LL << i))fib = multi(fib,r[i]);
    ans = multi(fib,{ { 1 }, { 1 } });
    print(ans[1][0].val());
    
    return 0;
}
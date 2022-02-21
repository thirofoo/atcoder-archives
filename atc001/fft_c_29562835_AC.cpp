/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/atc001/submissions/29562835
 * Submitted at: 2022-02-21 16:03:33
 * Problem URL: https://atcoder.jp/contests/atc001/tasks/fft_c
 * Result: AC
 * Execution Time: 335 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    //convolutionは、二つのvectorを引数に持つことで、
    //f(x)=3x^3+2x^2+x と g(x)=2x^3+7x^2+3x+1 の多項式乗算後の係数を求める。
    //(下の場合はi番目がx^iの係数になるようになっている)
    //普通に計算するとO(N^2)だが、高速フーリエ変換を行うことでO(NlogN)になっている。
    // vector<ll> x = {0,1,2,3},y = {1,3,7,2};
    // vector<ll> con = convolution_ll(x,y);
    // cout << con.size() << endl;
    // rep(i,con.size())cout << con[i] << " ";
    // cout << endl;

    cout << fixed << setprecision(15);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    vector<int> con = convolution(a,b);
    cout << 0 << endl;
    rep(i,2*n-1) {
        cout << con[i] << endl;
    }
    return 0;
}
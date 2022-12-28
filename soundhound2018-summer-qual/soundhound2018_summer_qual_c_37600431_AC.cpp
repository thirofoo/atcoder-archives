/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/soundhound2018-summer-qual/submissions/37600431
 * Submitted at: 2022-12-28 21:29:59
 * Problem URL: https://atcoder.jp/contests/soundhound2018-summer-qual/tasks/soundhound2018_summer_qual_c
 * Result: AC
 * Execution Time: 8 ms
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    
    // Point : 期待値の線形性
    // 平均値と聞くと (当てはまる事象数) / (全事象) と考えがち
    // => 1つ当たりの期待値を その個数倍していけないかを考える
    // => 今回はある2項の差の期待値は,他の2項の差によらない => 線形性
    double n,m,d; input(n,m,d);
    print( (m-1)*(d == 0 ? 1/n : 2*(n-d)/n/n) );
    
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc227/submissions/27694366
 * Submitted at: 2021-12-04 22:34:59
 * Problem URL: https://atcoder.jp/contests/abc227/tasks/abc227_a
 * Result: AC
 * Execution Time: 7 ms
 */

#include <bits/stdc++.h>
#include <cmath> //abs関数で絶対値を使える。
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < n; ++i)

int main(){
    int n,k,a;
    cin >> n >> k >> a;
    if((k+a-1)%n == 0) cout << n << endl;
    else cout << (k+a-1)%n << endl;
    return 0;
}
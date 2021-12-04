/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc210/submissions/27687649
 * Submitted at: 2021-12-04 17:45:11
 * Problem URL: https://atcoder.jp/contests/abc210/tasks/abc210_a
 * Result: AC
 * Execution Time: 10 ms
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
    int n,a,x,y,ans;
    cin >> n >> a >> x >> y;
    if(n <= a)ans = x*n;
    else ans = x*a + y*(n-a);
    cout << ans << endl;
    return 0;
}
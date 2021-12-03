/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc230/submissions/27671320
 * Submitted at: 2021-12-03 22:38:01
 * Problem URL: https://atcoder.jp/contests/abc230/tasks/abc230_a
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
    int a;
    cin >> a;
    if(a<10) cout << "AGC00" + to_string(a) << endl;
    else if(a<42) cout << "AGC0" + to_string(a) << endl;
    else cout << "AGC0" + to_string(a+1) << endl;
    return 0;
}

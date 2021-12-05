/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc131/submissions/27721063
 * Submitted at: 2021-12-05 22:10:54
 * Problem URL: https://atcoder.jp/contests/arc131/tasks/arc131_a
 * Result: WA
 * Execution Time: 8 ms
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
    ll a,b;
    cin >> a >> b;
    string b_ = to_string(b);
    ll i1 = a*pow(10,b_.size()) + b/2;
    cout << i1 << endl;
    return 0;
}
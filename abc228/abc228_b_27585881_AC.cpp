/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc228/submissions/27585881
 * Submitted at: 2021-11-29 14:25:40
 * Problem URL: https://atcoder.jp/contests/abc228/tasks/abc228_b
 * Result: AC
 * Execution Time: 61 ms
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
    int N,X;
    int ans = 1;
    cin >> N >> X;
    vector<int> convey(N);
    rep(i,N)cin >> convey[i];
    set<int> a;
    a.insert(X);
    int former = -1;
    int latter = -2;
    while(former != latter){
        former =a.size();
        a.insert(convey[X-1]);
        latter =a.size();
        X = convey[X-1];
    }
    cout << latter << endl;
    return 0;
}
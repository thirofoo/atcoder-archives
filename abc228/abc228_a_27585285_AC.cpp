/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc228/submissions/27585285
 * Submitted at: 2021-11-29 13:38:13
 * Problem URL: https://atcoder.jp/contests/abc228/tasks/abc228_a
 * Result: AC
 * Execution Time: 6 ms
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
    int S,T,X;
    cin >> S >> T >> X;
    if(S<T){
        if(X>=S && X<T)cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else if(T<S){
        if(X>=S || X<T)cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else cout << "Yes" << endl;
    return 0;
}
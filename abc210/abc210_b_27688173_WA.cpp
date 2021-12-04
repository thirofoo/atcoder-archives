/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc210/submissions/27688173
 * Submitted at: 2021-12-04 18:15:08
 * Problem URL: https://atcoder.jp/contests/abc210/tasks/abc210_b
 * Result: WA
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
    int n;
    int i = 0;
    string s;
    cin >> n;
    cin >> s;
    while(s[i] == '0')i++;
    cout << i << endl;
    if(i%2 == 0)cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc170/submissions/29357407
 * Submitted at: 2022-02-15 23:56:33
 * Problem URL: https://atcoder.jp/contests/abc170/tasks/abc170_a
 * Result: AC
 * Execution Time: 9 ms
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
    map<int,int> x;
    rep(i,5){
        int tmp; cin >> tmp;
        x[tmp]++;
    }
    rep(i,5)if(!x[i+1])cout << i+1 << endl;
    return 0;
}
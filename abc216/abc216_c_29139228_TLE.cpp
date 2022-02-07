/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc216/submissions/29139228
 * Submitted at: 2022-02-07 12:42:36
 * Problem URL: https://atcoder.jp/contests/abc216/tasks/abc216_c
 * Result: TLE
 * Execution Time: 2205 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,count = 0; cin >> n;
    while(true){
        if(n >= (1 << (count+1)))count++;
        else break;
    }
    int count2 = n - (1 << count);
    cout << "A";
    rep(i,count)cout << "B";
    rep(i,count2)cout << "A";
    cout << endl;
    return 0;
}
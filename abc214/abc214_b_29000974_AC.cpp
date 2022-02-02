/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc214/submissions/29000974
 * Submitted at: 2022-02-02 12:09:33
 * Problem URL: https://atcoder.jp/contests/abc214/tasks/abc214_b
 * Result: AC
 * Execution Time: 9 ms
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
    int s,t,count = 0; cin >> s >> t;
    rep(i,s+1)rep(j,s+1)rep(k,s+1){
        if(i*j*k <= t && i+j+k <= s)count++;
    }
    cout << count << endl;
    return 0;
}
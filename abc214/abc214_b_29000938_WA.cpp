/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc214/submissions/29000938
 * Submitted at: 2022-02-02 12:06:51
 * Problem URL: https://atcoder.jp/contests/abc214/tasks/abc214_b
 * Result: WA
 * Execution Time: 8 ms
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
    rep(i,s)rep(j,s)rep(k,s){
        if(i*j*s <= t)count++;
    }
    cout << count << endl;
    return 0;
}
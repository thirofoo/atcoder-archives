/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc222/submissions/28973596
 * Submitted at: 2022-01-31 18:36:34
 * Problem URL: https://atcoder.jp/contests/abc222/tasks/abc222_b
 * Result: AC
 * Execution Time: 31 ms
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
    int n,p,count = 0; cin >> n >> p;
    rep(i,n){
        int a; cin >> a;
        if(a < p)count++;
    }
    cout << count << endl;
    return 0;
}
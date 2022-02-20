/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc240/submissions/29507541
 * Submitted at: 2022-02-20 21:03:04
 * Problem URL: https://atcoder.jp/contests/abc240/tasks/abc240_b
 * Result: AC
 * Execution Time: 6 ms
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
    int n; cin >> n;
    set<int> ans;
    rep(i,n){
        int a; cin >> a;
        ans.insert(a);
    }
    cout << ans.size() << endl;
    return 0;
}
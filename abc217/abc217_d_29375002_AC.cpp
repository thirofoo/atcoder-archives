/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc217/submissions/29375002
 * Submitted at: 2022-02-16 23:48:42
 * Problem URL: https://atcoder.jp/contests/abc217/tasks/abc217_d
 * Result: AC
 * Execution Time: 383 ms
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
    int l,q; cin >> l >> q;
    set<int> length = {0,l};
    rep(i,q){
        int c,x; cin >> c >> x;
        if(c == 1)length.insert(x);
        else{
            auto itr = length.lower_bound(x);
            cout << *itr - *prev(itr) << endl;
        }
    }
    return 0;
}
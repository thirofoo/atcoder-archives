/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc226/submissions/28519058
 * Submitted at: 2022-01-15 15:20:42
 * Problem URL: https://atcoder.jp/contests/abc226/tasks/abc226_b
 * Result: AC
 * Execution Time: 199 ms
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
    int n,ans = 0; cin >> n;
    set<vector<int>> sequence;
    rep(i,n){
        int l; cin >> l;
        vector<int> tmp;
        rep(j,l){
            int a; cin >> a;
            tmp.push_back(a);
        }
        sequence.insert(tmp);
    }
    cout << sequence.size() << endl;
    return 0;
}
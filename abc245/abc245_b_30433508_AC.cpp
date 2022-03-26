/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc245/submissions/30433508
 * Submitted at: 2022-03-26 21:05:32
 * Problem URL: https://atcoder.jp/contests/abc245/tasks/abc245_b
 * Result: AC
 * Execution Time: 8 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n; cin >> n;
    set<int> a;
    rep(i,2005)a.insert(i);
    rep(i,n){
        int tmp; cin >> tmp;
        a.erase(tmp);
    }
    cout << *a.begin() << endl;
    return 0;
}
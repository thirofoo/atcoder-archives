/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc243/submissions/30034618
 * Submitted at: 2022-03-12 21:08:51
 * Problem URL: https://atcoder.jp/contests/abc243/tasks/abc243_b
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
    vector<int> a(n),b(n);
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];
    int ans1 = 0,ans2 = 0;
    set<int> aa,bb;
    rep(i,n){
        if(a[i] == b[i])ans1++;
        if(aa.count(b[i]))ans2++;
        if(bb.count(a[i]))ans2++;
        aa.insert(a[i]);
        bb.insert(b[i]);
    }
    cout << ans1 << endl << ans2 << endl;
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc209/submissions/29200799
 * Submitted at: 2022-02-10 21:41:04
 * Problem URL: https://atcoder.jp/contests/abc209/tasks/abc209_c
 * Result: AC
 * Execution Time: 78 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    mint ans = 1;
    int n,count = 0; cin >> n;
    vector<int> c;
    rep(i,n){
        int a; cin >> a;
        c.push_back(a);
    }
    sort(c.begin(),c.end());
    rep(i,n){
        if(count >= c[i])return cout << 0 << endl,0;
        ans *= (c[i]-count);
        count++;
    }
    cout << ans.val() << endl;
    return 0;
}
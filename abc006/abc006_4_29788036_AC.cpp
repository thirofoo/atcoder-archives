/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc006/submissions/29788036
 * Submitted at: 2022-03-01 17:38:27
 * Problem URL: https://atcoder.jp/contests/abc006/tasks/abc006_4
 * Result: AC
 * Execution Time: 19 ms
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

int LIS(vector<int> a){
    int n = a.size();
    vector<int> ans(n,INT_MAX);
    rep(i,n){     
        auto itr = lower_bound(ans.begin(),ans.end(),a[i]);
        *itr = a[i];
    }
    return lower_bound(ans.begin(),ans.end(),INT_MAX)-ans.begin();
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    cout << n-LIS(a) << endl;
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc238/submissions/29131425
 * Submitted at: 2022-02-06 22:21:18
 * Problem URL: https://atcoder.jp/contests/abc238/tasks/abc238_b
 * Result: AC
 * Execution Time: 7 ms
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
    int n,m = 0; cin >> n;
    vector<int> ans;
    rep(i,n){
        int tmp; cin >> tmp;
        if(i == 0)ans.push_back(tmp);
        else {
            tmp += *(ans.end()-1);
            tmp %= 360;
            ans.push_back(tmp);
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<=n;i++){
        if(i == 0)m = max(m,ans[i]);
        else if(i == n)m = max(m,360-ans[i-1]);
        else m = max(m,ans[i]-ans[i-1]);
    }
    cout << m << endl;
    return 0;
}
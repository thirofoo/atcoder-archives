/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc204/submissions/29812627
 * Submitted at: 2022-03-02 23:12:41
 * Problem URL: https://atcoder.jp/contests/abc204/tasks/abc204_d
 * Result: AC
 * Execution Time: 31 ms
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
    int n,sum = 0; cin >> n;
    vector<int> t(n);
    rep(i,n){
        cin >> t[i];
        sum += t[i];
    }
    vector<vector<bool>> dp(n+1,vector<bool>(n*1000+1,false));
    dp[0][0] = true;
    rep(i,n){
        rep(j,n*1000){
            if(!dp[i][j])continue;
            dp[i+1][j] = true;
            if(j+t[i] <= n*1000){
                dp[i+1][j+t[i]] = true;
            }
        }
    }

    vector<int> time;
    rep(i,n*1000+1){
        if(dp[n][i])time.push_back(i);
    }
    auto itr = upper_bound(time.begin(),time.end(),sum/2);
    if(abs(*itr-sum/2) <= abs(*(itr-1)-sum/2)){
        cout << max(*itr,sum-*itr) << endl;
    }
    else{
        cout << max(*(itr-1),sum-*(itr-1)) << endl;
    }
    return 0;
}
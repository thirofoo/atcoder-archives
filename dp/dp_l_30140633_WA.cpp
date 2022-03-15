/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/30140633
 * Submitted at: 2022-03-15 13:01:42
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_l
 * Result: WA
 * Execution Time: 119 ms
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

int total;

int dfs(int l,int r,vector<int>& a,vector<vector<int>>& dp,vector<vector<bool>>& visited){
    if(visited[l][r])return dp[l][r];
    visited[l][r] = true;
    if(l == r)return dp[l][r] = a[l];

    dp[l][r] = max(a[l]-dfs(l+1,r,a,dp,visited),a[r]-dfs(l,r-1,a,dp,visited));

    return dp[l][r];
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    vector<vector<int>> dp(n,vector<int>(n,-INT_MAX));
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    total = n-1;

    cout << dfs(0,n-1,a,dp,visited) << endl;
    return 0;
}
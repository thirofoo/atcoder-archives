/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/29965737
 * Submitted at: 2022-03-09 12:39:22
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_l
 * Result: AC
 * Execution Time: 150 ms
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
typedef modint1000000007 mint1;
typedef modint998244353 mint2;
#define rep(i, n) for(ll i = 0; i < n; i++)

//この発想は出てこない。
ll dfs(int l,int r,vector<vector<ll>>& dp,vector<vector<bool>>& frag, vector<int>& a){
    if(frag[l][r])return dp[l][r];
    frag[l][r] = true;
    if(l == r)return dp[l][r] = a[l];
    //ここが天才
    return dp[l][r] = max(a[l]-dfs(l+1,r,dp,frag,a),a[r]-dfs(l,r-1,dp,frag,a));
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    vector<vector<ll>> dp(n,vector<ll>(n,0));
    vector<vector<bool>> frag(n,vector<bool>(n,false));

    cout << dfs(0,n-1,dp,frag,a) << endl;

    return 0;
}
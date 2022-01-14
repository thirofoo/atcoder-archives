/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28503032
 * Submitted at: 2022-01-14 15:20:12
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_az
 * Result: TLE
 * Execution Time: 2205 ms
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

int s = 1000000007;
ll ans = 0;

void dfs(vector<vector<int>> const &num,int a,ll sum){
    for(int k:num[a]){
        sum *= k;
        if(a+1 <= num.size()-1) dfs(num,a+1,sum);
        else (ans += sum) %= s;
        sum /= k;
    }
}

int main() {
    int n; cin >> n;
    vector<vector<int>> number(n,vector<int>(6));
    rep(i,n)rep(j,6)cin >> number[i][j];
    dfs(number,0,1LL);
    cout << ans << endl;
    return 0;
}
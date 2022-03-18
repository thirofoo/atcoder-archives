/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc184/submissions/30204398
 * Submitted at: 2022-03-18 19:53:47
 * Problem URL: https://atcoder.jp/contests/abc184/tasks/abc184_d
 * Result: AC
 * Execution Time: 39 ms
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

int a,b,c;

double dfs(int A,int B,int C,vector<vector<vector<double>>>& memo,vector<vector<vector<bool>>>& visited){
    if(visited[A][B][C])return memo[A][B][C];
    visited[A][B][C] = true;
    if(A == 100 || B == 100 || C == 100)return memo[A][B][C];

    memo[A][B][C] += (dfs(A+1,B,C,memo,visited)+1)*((double)(A)/(A+B+C));
    memo[A][B][C] += (dfs(A,B+1,C,memo,visited)+1)*((double)(B)/(A+B+C));
    memo[A][B][C] += (dfs(A,B,C+1,memo,visited)+1)*((double)(C)/(A+B+C));

    return memo[A][B][C];
}

int main() {
    cout << fixed << setprecision(10);
    cin >> a >> b >> c;
    vector<vector<vector<double>>> memo(101,vector<vector<double>>(101,vector<double>(101,0)));
    vector<vector<vector<bool>>> visited(101,vector<vector<bool>>(101,vector<bool>(101,false)));
    cout << dfs(a,b,c,memo,visited) << endl;
    return 0;
}
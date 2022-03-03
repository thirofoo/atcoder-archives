/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc236/submissions/29824039
 * Submitted at: 2022-03-03 18:26:46
 * Problem URL: https://atcoder.jp/contests/abc236/tasks/abc236_d
 * Result: AC
 * Execution Time: 95 ms
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

int n,x = 0;

void dfs(int mem,int ans,vector<vector<int>>& a){
    if(mem == (1 << 2*n)-1){
        x = max(x,ans);
        return;
    }

    int p1,p2;
    //一人目
    rep(i,2*n){
        if(!(mem & (1 << i))){
            p1 = i;
            mem |= (1 << p1);
            break;
        }
    }
    //二人目
    rep(i,2*n){
        if(!(mem & (1 << i))){
            p2 = i;
            mem |= (1 << p2);
            dfs(mem,ans^a[p1][p2],a);
            mem ^= (1 << p2);
        }
    }
}

int main() {
    cin >> n;
    vector<vector<int>> a(2*n,vector<int>(2*n,-1));
    rep(i,2*n){
        for(int j=i+1;j<2*n;j++){
            cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    }
    dfs(0,0,a);
    cout << x << '\n';
    return 0;
}
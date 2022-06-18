/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc256/submissions/32556400
 * Submitted at: 2022-06-18 21:37:43
 * Problem URL: https://atcoder.jp/contests/abc256/tasks/abc256_c
 * Result: AC
 * Execution Time: 249 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

vector<vector<int>> field(3,vector<int>(3,0));
vector<int> h(3),w(3);
ll ans = 0;

void dfs(int s){
    if(s == 3){
        rep(i,3){
            int tmp = 0;
            rep(j,3)tmp += field[j][i];
            if(tmp != w[i])return;
        }
        ans++;
        return;
    }
    for(int i=1;i<h[s];i++){
        for(int j=1;i+j<h[s];j++){
            field[s][0] = i;
            field[s][1] = j;
            field[s][2] = h[s]-i-j;
            dfs(s+1);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    rep(i,3)cin >> h[i];
    rep(i,3)cin >> w[i];
    dfs(0);
    cout << ans << endl;

    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc129/submissions/29181226
 * Submitted at: 2022-02-09 19:26:35
 * Problem URL: https://atcoder.jp/contests/abc129/tasks/abc129_d
 * Result: AC
 * Execution Time: 410 ms
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
    int h,w,ans = 0; cin >> h >> w;
    vector<string> field(h);
    rep(i,h)cin >> field[i];
    vector<vector<int>> obs_x(h+1),obs_y(w+1);
    rep(i,h)obs_x[i+1].push_back(0);
    rep(i,w)obs_y[i+1].push_back(0);
    rep(i,h)rep(j,w)if(field[i][j] == '#')obs_x[i+1].push_back(j+1);
    rep(i,h)rep(j,w)if(field[i][j] == '#')obs_y[j+1].push_back(i+1);
    rep(i,h)obs_x[i+1].push_back(w+1);
    rep(i,w)obs_y[i+1].push_back(h+1);
    rep(i,h){
        rep(j,w){
            if(field[i][j] == '#'){cout << "   "; continue;}
            int itr_x = lower_bound(obs_x[i+1].begin(),obs_x[i+1].end(),j+1) - obs_x[i+1].begin(); 
            int itr_y = lower_bound(obs_y[j+1].begin(),obs_y[j+1].end(),i+1) - obs_y[j+1].begin();
            int x = obs_x[i+1][itr_x] - obs_x[i+1][itr_x-1] -1;
            int y = obs_y[j+1][itr_y] - obs_y[j+1][itr_y-1] -1;
            ans = max(ans,x+y-1);
            // cout << x+y-1 << "  ";
        }
        // cout << endl;
    }
    cout << ans << endl;
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/29420683
 * Submitted at: 2022-02-19 17:25:36
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_bk
 * Result: AC
 * Execution Time: 63 ms
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

int cnt_num(vector<int> r){
    int result = 0;
    map<int,int> cnt;
    rep(i,r.size()){
        cnt[r[i]]++;
        result = max(result,cnt[r[i]]);
    }
    return result;
}

int main(){
    int h,w,ans = 0; cin >> h >> w;
    vector<vector<int>> grid(h,vector<int>(w));
    rep(i,h)rep(j,w)cin >> grid[i][j];
    for(int i=1;i<(1 << h);i++){
        vector<int> r;
        int r_cnt = 0;
        for(int j=0;j<w;j++){
            int tmp = 0;
            bool frag = true;
            for(int k=0;k<h;k++){
                if(i & (1 << k)){
                    r_cnt++;
                    if(tmp == 0)tmp = grid[k][j];
                    else if(tmp != grid[k][j])frag = false;
                }
            }
            if(frag)r.push_back(tmp);
        }
        ans = max(ans,cnt_num(r)*(r_cnt/w));
    }
    cout << ans << endl;
    return 0;
}
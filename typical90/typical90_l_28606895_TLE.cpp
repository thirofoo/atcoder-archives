/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28606895
 * Submitted at: 2022-01-18 00:20:32
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_l
 * Result: TLE
 * Execution Time: 2206 ms
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

vector<int> x = {0,0,1,-1};
vector<int> y = {1,-1,0,0};

void dfs(int ra,int ca,int rb,int cb,vector<vector<int>> &field,vector<vector<bool>> &tmp,int h,int w){
    for(int i=0;i<4;i++){
        if(ra+x[i] >= 0 && ra+x[i] < h  && ca+y[i] >= 0 && ca+y[i] < w && field[ra+x[i]][ca+y[i]] && !tmp[ra+x[i]][ca+y[i]]){
            tmp[ra+x[i]][ca+y[i]] = true;
            dfs(ra+x[i],ca+y[i],rb,cb,field,tmp,h,w);
        }
    }
}

int main() {
    int h,w,Q; cin >> h >> w >> Q;
    vector<vector<int>> field(h,vector<int>(w,0));
    rep(i,Q){
        int q,ra,ca; cin >> q;
        if(q == 1){
            cin >> ra >> ca;
            field[ra-1][ca-1] = 1;
        }
        else{
            int rb,cb;
            cin >> ra >> ca >> rb >> cb;
            if(!field[ra-1][ca-1] || !field[rb-1][cb-1]){
                cout << "No" << endl;
                continue;
            }
            vector<vector<bool>> tmp(h,vector<bool>(w,false));
            tmp[ra-1][ca-1] = true;
            dfs(ra-1,ca-1,rb-1,cb-1,field,tmp,h,w);
            if(tmp[rb-1][cb-1])cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}
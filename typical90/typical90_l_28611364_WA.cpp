/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28611364
 * Submitted at: 2022-01-18 10:53:53
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_l
 * Result: WA
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
vector<vector<int>> tmp;

void dfs(int ra,int ca,int rb,int cb,vector<vector<int>> &field,vector<vector<int>> &U,int h,int w){
    for(int i=0;i<4;i++){
        int chx = ra+x[i], chy = ca+y[i]; 
        if(chx >= 0 && chx < h  && chy >= 0 && chy < w && field[chx][chy] && U[chx][chy] == tmp[chx][chy]){
            U[chx][chy]++;
            dfs(chx,chy,rb,cb,field,U,h,w);
        }
    }
}

int main() {
    int h,w,Q; cin >> h >> w >> Q;
    vector<vector<int>> field(h,vector<int>(w,0));
    vector<vector<int>> U(h,vector<int>(w,0));
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
            U[ra-1][ca-1]++;
            tmp = U;
            dfs(ra-1,ca-1,rb-1,cb-1,field,U,h,w);
            if(U[rb-1][cb-1])cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}
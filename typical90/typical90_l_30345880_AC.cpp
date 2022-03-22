/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/30345880
 * Submitted at: 2022-03-22 17:26:57
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_l
 * Result: AC
 * Execution Time: 228 ms
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

vector<int> vx = {1,0,-1,0};
vector<int> vy = {0,1,0,-1};

int main() {
    int h,w,q; cin >> h >> w >> q;
    vector<vector<bool>> field(h,vector<bool>(w,false));
    dsu d(h*w+5);
    rep(i,q){
        int t; cin >> t;
        if(t == 1){
            int r,c; cin >> r >> c;
            r--; c--;
            field[r][c] = true;
            rep(i,4){
                if(0 <= r+vx[i] && r+vx[i] < h && 0 <= c+vy[i] && c+vy[i] < w && field[r+vx[i]][c+vy[i]]){
                    d.merge(w*r+c,w*(r+vx[i])+c+vy[i]);
                }
            }
        }
        else{
            int ra,ca,rb,cb; cin >> ra >> ca >> rb >> cb;
            ra--; ca--; rb--; cb--;
            if(field[ra][ca] && field[rb][cb] && d.same(w*ra+ca,w*rb+cb))cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}
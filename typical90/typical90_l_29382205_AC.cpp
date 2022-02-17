/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/29382205
 * Submitted at: 2022-02-17 13:40:25
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_l
 * Result: AC
 * Execution Time: 232 ms
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
    int h,w,q; cin >> h >> w >> q;
    vector<vector<bool>> field(h+1,vector<bool>(w+1));
    dsu d(h*w+1);
    rep(i,q){
        int t; cin >> t;
        if(t == 1){
            int r,c; cin >> r >> c;
            field[r][c] = true;
            if(c != 1 && field[r][c-1])d.merge(w*(r-1)+c,w*(r-1)+c-1);
            if(c != w && field[r][c+1])d.merge(w*(r-1)+c,w*(r-1)+c+1);
            if(r != 1 && field[r-1][c])d.merge(w*(r-1)+c,w*(r-2)+c);
            if(r != h && field[r+1][c])d.merge(w*(r-1)+c,w*r+c);
        }
        else{
            int ra,ca,rb,cb; cin >> ra >> ca >> rb >> cb;
            if(!field[ra][ca] || !field[rb][cb])cout << "No" << endl;
            else{
                if(d.same(w*(ra-1)+ca,w*(rb-1)+cb))cout << "Yes" << endl;
                else cout << "No" << endl;
            }
        }
    }
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc009/submissions/30414100
 * Submitted at: 2022-03-26 15:43:02
 * Problem URL: https://atcoder.jp/contests/ahc009/tasks/ahc009_a
 * Result: AC
 * Execution Time: 3 ms
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

vector<int> vx = {-1,0,1,0};
vector<int> vy = {0,1,0,-1};

int main() {
    int sx,sy,tx,ty; double p; cin >> sx >> sy >> tx >> ty >> p;
    vector<string> r_wall(20),d_wall(19);
    rep(i,20)cin >> r_wall[i];
    rep(i,19)cin >> d_wall[i];

    int cnt = 0,nx = sx,ny = sy,time = 10;
    string ans = "";
    // while(time--){
    //     bool frag1 = nx <= tx;
    //     bool frag2 = ny <= ty;

    //     if(frag1){
    //         while(true){
    //             if(nx >= 19 || d_wall[nx][ny])break;
    //             ans += "D";
    //             nx++;
    //         }
    //     }
    //     else{
    //         while(true){
    //             if(nx-1 < 0 || d_wall[nx-1][ny])break;
    //             ans += "U";
    //             nx--;
    //         }
    //     }

    //     if(frag2){
    //         while(true){
    //             if(nx >= 19 || r_wall[nx][ny])break;
    //             ans += "R";
    //             ny++;
    //         }
    //     }
    //     else{
    //         while(true){
    //             if(ny-1 < 0 || r_wall[nx][ny-1])break;
    //             ans += "L";
    //             ny--;
    //         }
    //     }
    // }
    while(ans.size() < 200){
        ans += "URDL";
        if(nx <= tx){
            nx += 2;
            ans += "DD";
        }
        else{
            nx -= 2;
            ans += "UU";
        }

        if(ny <= ty){
            ny += 2;
            ans += "RR";
        }
        else{
            ny -= 2;
            ans += "LL";
        }
    }
    ans.resize(200);
    cout << ans << endl;

    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc009/submissions/30419786
 * Submitted at: 2022-03-26 17:54:46
 * Problem URL: https://atcoder.jp/contests/ahc009/tasks/ahc009_a
 * Result: CE
 * Execution Time: None ms
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
 
unsigned int randInt() {
    static unsigned int tx = 123456789, ty=362436069, tz=521288629, tw=88675123;
    unsigned int tt = (tx^(tx<<11));
    tx = ty; ty = tz; tz = tw;
    return ( tw=(tw^(tw>>19))^(tt^(tt>>8)) );
}
 
int main() {
    int sx,sy,tx,ty; double p; cin >> sx >> sy >> tx >> ty >> p;
    vector<string> r_wall(20),d_wall(19);
    rep(i,20)cin >> r_wall[i];
    rep(i,19)cin >> d_wall[i];

    rep(i,20)r_wall[i] += "1";
    d_wall.push_back("11111111111111111111");
    int rand = (int)((double)1/p);

    rep(i,20){
        rep(j,20){
            if(i == 0 || j == 0)continue;
            if(r_wall[i][j] && d_wall[i][j]){
                d_wall[i-1][j] = '1';
            }
        }
    }
 
    int nx = sx,ny = sy;
    string ans = "";
    while(ans.size() < 160){
        ans += "R";
        ans += "D";
        if(randInt()%rand)ans += "R";
        if(randInt()%rand)ans += "D";
        if(ans.size()%10 == 5){
            ans += "UUR";
        }
        else if(ans.size()%10 == 0){
            ans += "LLD";
        }
    }
    while(ans.size() <= 200)ans += "RRRDDDLLLUUU"
    ans.resize(200);
    cout << ans << endl;
    return 0;
}
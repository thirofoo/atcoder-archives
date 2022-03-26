/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc009/submissions/30422560
 * Submitted at: 2022-03-26 18:44:41
 * Problem URL: https://atcoder.jp/contests/ahc009/tasks/ahc009_a
 * Result: AC
 * Execution Time: 8 ms
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < n; i++)
 
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

    int rand = (int)((double)1/p);
 
    int nx = sx,ny = sy;
    string ans = "";
    while(ans.size() < 160){
        ans += "RD";
        if(randInt()%rand)ans += "R";
        if(randInt()%rand)ans += "D";
        if(ans.size()%11 == 5){
            ans += "UUR";
        }
        else if(ans.size()%10 == 0){
            ans += "LLD";
        }
    }
    while(ans.size() <= 200)ans += "RRRDDDLLLUUU";
    ans.resize(200);
    cout << ans << endl;
    return 0;
}
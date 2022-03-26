/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc009/submissions/30414303
 * Submitted at: 2022-03-26 15:49:11
 * Problem URL: https://atcoder.jp/contests/ahc009/tasks/ahc009_a
 * Result: WA
 * Execution Time: 12 ms
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
    int rand = (int)((double)1/p);
    cout << rand << endl;

    int cnt = 0,nx = sx,ny = sy,time = 10;
    string ans = "";
    while(ans.size() < 200){
        ans += "URDL";
        if(nx <= tx){
            if(randInt()%rand){
                ans += "D";
                nx++;
            }
            if(randInt()%rand){
                ans += "D";
                nx++;
            }
        }
        else{
            if(randInt()%rand){
                ans += "U";
                nx--;
            }
            if(randInt()%rand){
                ans += "U";
                nx--;
            }
        }

        if(ny <= ty){
            if(randInt()%rand){
                ans += "R";
                ny++;
            }
            if(randInt()%rand){
                ans += "R";
                ny++;
            }
        }
        else{
            if(randInt()%rand){
                ans += "L";
                ny--;
            }
            if(randInt()%rand){
                ans += "L";
                ny--;
            }
        }
    }
    ans.resize(200);
    cout << ans << endl;
    return 0;
}
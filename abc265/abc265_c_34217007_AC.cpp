/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc265/submissions/34217007
 * Submitted at: 2022-08-21 21:21:34
 * Problem URL: https://atcoder.jp/contests/abc265/tasks/abc265_c
 * Result: AC
 * Execution Time: 8 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h,w; cin >> h >> w;
    vector<string> field(h);
    rep(i,h)cin >> field[i];
    int x = 0,y = 0,cnt = 0;
    while(true){
        if(cnt > h*w+5)break;
        if(field[x][y] == 'U'){
            if(x == 0)break;
            else x--;
        }
        else if(field[x][y] == 'D'){
            if(x == h-1)break;
            else x++;
        }
        else if(field[x][y] == 'L'){
            if(y == 0)break;
            else y--;
        }
        else if(field[x][y] == 'R'){
            if(y == w-1)break;
            else y++;
        }
        cnt++;
    }
    if(cnt > h*w)cout << -1 << endl;
    else cout << x+1 << " " << y+1 << endl;
    
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc131/submissions/27731787
 * Submitted at: 2021-12-06 11:42:32
 * Problem URL: https://atcoder.jp/contests/arc131/tasks/arc131_b
 * Result: AC
 * Execution Time: 48 ms
 */

#include <bits/stdc++.h>
#include <cmath> //abs関数で絶対値を使える。
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
#define rep(i,n) for(ll i=0; i<n; ++i)

int main(){
    ll h,w;
    cin >> h >> w;
    vector<vector<char>> color(h+2,vector<char>(w+2));
    rep(i,h+2){
        rep(j,w+2){
            if(i == 0 || i == h+1 || j == 0 || j == w+1){
                color[i][j] = '0';
                continue;
            }
            cin >> color[i][j];
        }
    }
    rep(i,h){
        rep(j,w){
            if(color[i+1][j+1] == '.'){
                for(char k:{'1','2','3','4','5'}){
                    if(k != color[i][j+1] && k != color[i+1][j] && k != color[i+2][j+1] && k != color[i+1][j+2]){
                        color[i+1][j+1] = k;
                        break;
                    }
                }
            }
        }
    }
    rep(i,h){
        rep(j,w)cout << color[i+1][j+1];
        cout << endl;
    }
    return 0;
}
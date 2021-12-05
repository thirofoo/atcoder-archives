/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc131/submissions/27725389
 * Submitted at: 2021-12-05 22:59:21
 * Problem URL: https://atcoder.jp/contests/arc131/tasks/arc131_b
 * Result: RE
 * Execution Time: 137 ms
 */

#include <bits/stdc++.h>
#include <cmath> //abs関数で絶対値を使える。
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < n; ++i)

int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<int>> color(h+2, vector<int>(w+2));
    rep(i,h+2){
        rep(j,w+2){
            if(i == 0 || j == 0 || i == h+1 || j == w+1){
                color[i+1][j+1] = 0;
            }
            string a;
            cin >> a;
            if(a == "1" || a == "2" || a == "3" || a == "4" || a =="5")color[i+1][j+1] = stoi(a);
            else color[i+1][j+1] = 0;
        }
    }
    rep(i,h){
        rep(j,w){
            for(int k=1;i<6;i++){
                if(k != color[i][j+1] && k != color[i+1][j] && k != color[i+2][j+1] && k != color[i+1][j+2]){
                    color[i+1][j+1] = k;
                    break;
                }
            }
        }
    }
    rep(i,h){
        rep(j,w){
            cout << color[i+1][j+1];
        }
        cout << endl;
    }
    return 0;
}
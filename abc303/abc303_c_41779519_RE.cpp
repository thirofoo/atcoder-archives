/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc303/submissions/41779519
 * Submitted at: 2023-05-27 23:48:01
 * Problem URL: https://atcoder.jp/contests/abc303/tasks/abc303_c
 * Result: RE
 * Execution Time: 184 ms
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n,m,h,k;
    string s;
    cin >> n >> m >> h >> k >> s;
    int x = 0,y = 0;
    vector<vector<int>> w(m,vector<int>(2));
    for(int i=0;i<m;i++){
        for(int j=0;j<2;j++){
            cin >> w.at(i).at(j);
        }
    }
    for(int i=0;i<n;i++){
        if(s[i] == 'R')x++;
        if(s[i] == 'L')x--;
        if(s[i] == 'U')y++;
        if(s[i] == 'D')y--;
        h--;
        if(h < 0)return cout << "No" << endl,0;
        if(h < k){
            for(int j=0;j<m;j++){
                if(x == w[j][0] && y == w[j][1]){
                    h = k;
                    w.erase(w.begin()+j);
                }
            }
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}


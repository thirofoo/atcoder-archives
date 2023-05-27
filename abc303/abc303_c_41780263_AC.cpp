/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc303/submissions/41780263
 * Submitted at: 2023-05-28 00:09:52
 * Problem URL: https://atcoder.jp/contests/abc303/tasks/abc303_c
 * Result: AC
 * Execution Time: 178 ms
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n,m,h,k;
    string s;
    cin >> n >> m >> h >> k >> s;
    int x = 0,y = 0;
    set<pair<int,int>> w;
    for(int i=0;i<m;i++){
        for(int j=0;j<2;j++){
            int x,y; cin >> x >> y;
            w.insert(pair(x,y));
        }
    }

    for(int i=0;i<n;i++){
        if(s[i] == 'R')x++;
        if(s[i] == 'L')x--;
        if(s[i] == 'U')y++;
        if(s[i] == 'D')y--;
        h--;
        if(h < 0)return cout << "No" << endl,0;

        // まだ一度も使ってない回復薬がある & h > k
        if(h < k && w.count(pair(x,y))){
            h = k;
            w.erase(pair(x,y));
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}


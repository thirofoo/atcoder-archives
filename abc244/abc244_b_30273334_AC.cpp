/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc244/submissions/30273334
 * Submitted at: 2022-03-20 21:05:31
 * Problem URL: https://atcoder.jp/contests/abc244/tasks/abc244_b
 * Result: AC
 * Execution Time: 13 ms
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

vector<int> vx = {1,0,-1,0};
vector<int> vy = {0,-1,0,1};

int main() {
    int n; string t; cin >> n >> t;
    int cnt = 0,x = 0,y = 0;
    rep(i,t.size()){
        if(t[i] == 'S'){
            x += vx[cnt%4];
            y += vy[cnt%4];
        }
        else cnt++;
    }
    cout << x << " " << y << endl;
    return 0;
}
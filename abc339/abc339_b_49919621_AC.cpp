/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc339/submissions/49919621
 * Submitted at: 2024-02-03 21:06:57
 * Problem URL: https://atcoder.jp/contests/abc339/tasks/abc339_b
 * Result: AC
 * Execution Time: 1 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

vector<int> dx = {-1,0,1,0};
vector<int> dy = {0,1,0,-1};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h, w, n; cin >> h >> w >> n;
    vector<string> s(h);
    rep(i,h) rep(j,w) s[i] += '.';
    ll x = 0, y = 0, dir = 0;
    while(n--) {
        if( s[x][y] == '.' ) {
            s[x][y] = '#';
            dir = (dir + 1) % 4;
        }
        else {
            s[x][y] = '.';
            dir = (dir - 1 + 4) % 4;
        }
        x += dx[dir];
        y += dy[dir];
        x = (x + h) % h;
        y = (y + w) % w;
    }
    rep(i,h) cout << s[i] << endl;
    
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc244/submissions/50216912
 * Submitted at: 2024-02-12 09:02:28
 * Problem URL: https://atcoder.jp/contests/abc244/tasks/abc244_b
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
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

// 左上右下の順番
vector<int> dx = {1,0,-1,0};
vector<int> dy = {0,-1,0,1};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; string t; cin >> n >> t;
    ll dir = 0, nx = 0, ny = 0;
    rep(i,n) {
        if( t[i] == 'S' ) {
            nx += dx[dir];
            ny += dy[dir];
        }
        else dir = (dir+1)%4;
    }
    cout << nx << " " << ny << endl;
    
    return 0;
}
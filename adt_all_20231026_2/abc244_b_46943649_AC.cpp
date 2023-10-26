/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/adt_all_20231026_2/submissions/46943649
 * Submitted at: 2023-10-26 18:35:53
 * Problem URL: https://atcoder.jp/contests/adt_all_20231026_2/tasks/abc244_b
 * Result: AC
 * Execution Time: 2 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

// 左上右下の順番
vector<int> dx = {1,0,-1,0};
vector<int> dy = {0,-1,0,1};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; string t; cin >> n >> t;
    ll nx = 0, ny = 0, dir = 0;
    rep(i,n) {
        if( t[i] == 'S' ) {
            nx += dx[dir%4];
            ny += dy[dir%4];
        }
        else dir++;
    }
    cout << nx << " " << ny << endl;
    
    return 0;
}
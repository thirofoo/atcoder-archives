/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc109/submissions/44575601
 * Submitted at: 2023-08-14 10:11:43
 * Problem URL: https://atcoder.jp/contests/abc109/tasks/abc109_d
 * Result: AC
 * Execution Time: 226 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h,w; cin >> h >> w;
    vector<vector<ll>> a(h,vector<ll>(w));
    rep(i,h)rep(j,w) {
        cin >> a[i][j];
        a[i][j] %= 2;
    }
    // 一番下に移動させて横移動するのが最適そう？
    vector<T> ans;
    rep(i,h-1)rep(j,w) {
        if( a[i][j] ) {
            a[i][j] = 0;
            a[i+1][j] = (a[i+1][j]+1)%2;
            ans.push_back(T(i,j,i+1,j));
        }
    }
    rep(j,w-1) {
        if( a[h-1][j] ) {
            a[h-1][j] = 0;
            a[h-1][j+1] = (a[h-1][j+1]+1)%2;
            ans.push_back(T(h-1,j,h-1,j+1));
        }
    }
    cout << ans.size() << endl;
    for(auto [x1,y1,x2,y2]:ans) cout << x1+1 << " " << y1+1 << " " << x2+1 << " " << y2+1 << endl;
    
    return 0;
}
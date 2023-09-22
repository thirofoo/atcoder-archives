/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc258/submissions/45783737
 * Submitted at: 2023-09-22 09:42:17
 * Problem URL: https://atcoder.jp/contests/abc258/tasks/abc258_b
 * Result: AC
 * Execution Time: 1 ms
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

#define DIR_NUM 8
vector<int> dx = {0,-1,0,1,1,-1,-1,1};
vector<int> dy = {-1,0,1,0,1,-1,1,-1};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<string> a(n);
    rep(i,n) cin >> a[i];
    ll ans = -1;
    rep(i,n) {
        rep(j,n) {
            rep(d,DIR_NUM) {
                ll cand = 0;
                ll now_x = i, now_y = j;
                rep(_,n) {
                    cand *= 10;
                    cand += a[now_x][now_y] - '0';
                    now_x += dx[d] + n, now_y += dy[d] + n;
                    now_x %= n, now_y %= n;
                }
                ans = max(ans, cand);
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}
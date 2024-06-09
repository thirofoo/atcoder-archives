/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc357/submissions/54399748
 * Submitted at: 2024-06-09 15:58:25
 * Problem URL: https://atcoder.jp/contests/abc357/tasks/abc357_c
 * Result: AC
 * Execution Time: 11 ms
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
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 再帰関数でやるととっても楽 (外から固めていく感じ)
    ll n; cin >> n;
    ll size = pow(3,n);
    vector<vector<char>> s(size, vector<char>(size,'.'));
    auto f = [&](auto self, ll x, ll y, ll num) -> void {
        if(num == 0) {
            s[x][y] = '#';
            return;
        }
        rep(i, 3) rep(j, 3) {
            // 3*3 と見なした時の中央は skip
            if(i == 1 && j == 1) continue;
            self(self, x+i*pow(3, num-1), y+j*pow(3, num-1), num-1);
        }
        return;
    };
    f(f, 0, 0, n);
    rep(i, size) {
        rep(j, size) cout << s[i][j];
        cout << endl;
    }

    return 0;
}
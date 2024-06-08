/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc357/submissions/54345909
 * Submitted at: 2024-06-08 21:19:20
 * Problem URL: https://atcoder.jp/contests/abc357/tasks/abc357_c
 * Result: RE
 * Execution Time: 75 ms
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
    
    ll n; cin >> n;
    vector s(n+1, vector<string>{});
    s[0] = {"#"};
    s[1] = {"###", "#.#", "###"};
    reps(i,2,n+1) {
        ll size = s[i-1].size();
        vector<string> tmp(3*size, "");
        rep(j, 3*size) {
            rep(k, size) {
                tmp[j] += s[i-1][j%size][k];
            }
        }
        rep(j, size) {
            rep(k, size) {
                tmp[j] += s[i-1][j%size][k];
            }
        }
        rep(j, size) {
            rep(k, size) {
                tmp[j+size] += ".";
            }
        }
        rep(j, size) {
            rep(k, size) {
                tmp[j+2*size] += s[i-1][j%size][k];
            }
        }
        rep(j, 3*size) {
            rep(k, size) {
                tmp[j] += s[i-1][j%size][k];
            }
        }
        s[i] = tmp;
    }
    rep(i, s[n].size()) {
        cout << s[n][i] << endl;
    }
    
    return 0;
}
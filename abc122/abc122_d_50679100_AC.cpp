/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc122/submissions/50679100
 * Submitted at: 2024-02-27 17:45:18
 * Problem URL: https://atcoder.jp/contests/abc122/tasks/abc122_d
 * Result: AC
 * Execution Time: 2 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    if( n == 3 ) return cout << 61 << endl, 0;
    const vector<char> c = {'A', 'G', 'C', 'T'};
    const set<string> ng = {
        "AAGC", "CAGC", "GAGC", "TAGC", "AAGC", "ACGC", "AGGC", "ATGC", "AGAC", "AGCC", "AGGC", "AGTC", "AGCA", "AGCC", "AGCG", "AGCT", 
        "AACG", "CACG", "GACG", "TACG", "ACGA", "ACGC", "ACGG", "ACGT", 
        "AGAC", "CGAC", "GGAC", "TGAC", "GACA", "GACC", "GACG", "GACT", 
    };
    const ll size = 4;
    vector dp(n+1,vector(size,vector(size,vector(size, vector<mint>(2,0)))));
    // dp[i][j][k][l][l] : i 文字目まで 1, 2, 3 個前が j,k,l で過去に AGC or ACG or GAC があるか m
    // j,k : 0 無, 1 A, 2 G, 3 C, 4 T
    rep(i,size) rep(j,size) rep(k,size) {
        string s = "";
        s += c[i], s += c[j], s += c[k];
        dp[3][i][j][k][ng.count(s)]++;
    }
    reps(i,1,n) rep(j,size) rep(k,size) rep(l,size) rep(m,2) {
        rep(next, size) {
            string s = "";
            s += c[j], s += c[k], s += c[l], s += c[next];
            dp[i+1][k][l][next][m || ng.count(s)] += dp[i][j][k][l][m];
        }
    }
    mint ans = 0;
    rep(i,size) rep(j,size) rep(k,size) ans += dp[n][i][j][k][0];
    cout << ans.val() << endl;
    
    return 0;
}
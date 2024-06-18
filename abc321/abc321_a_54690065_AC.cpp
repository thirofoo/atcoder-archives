/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc321/submissions/54690065
 * Submitted at: 2024-06-18 18:12:21
 * Problem URL: https://atcoder.jp/contests/abc321/tasks/abc321_a
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
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string n; cin >> n;
    ll now = INF;
    rep(i, n.size()) {
        if(n[i]-'0' < now) {
            now = n[i]-'0';
        }
        else return cout << "No" << endl, 0;
    }
    cout << "Yes" << endl;
    
    return 0;
}
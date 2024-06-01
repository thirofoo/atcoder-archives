/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc356/submissions/54074694
 * Submitted at: 2024-06-01 21:00:48
 * Problem URL: https://atcoder.jp/contests/abc356/tasks/abc356_a
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
    
    ll n, l, r; cin >> n >> l >> r;
    vector<ll> p(n,0);
    iota(p.begin(), p.end(), 1);
    reverse(p.begin()+l-1, p.begin()+r);
    for(auto x : p) cout << x << " ";
    cout << endl;
    
    return 0;
}
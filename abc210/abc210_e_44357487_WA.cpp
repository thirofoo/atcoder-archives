/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc210/submissions/44357487
 * Submitted at: 2023-08-07 16:13:33
 * Problem URL: https://atcoder.jp/contests/abc210/tasks/abc210_e
 * Result: WA
 * Execution Time: 32 ms
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

inline long long GCD(long long a, long long b){
    // 負 or a == 0 で -1
    if( a <= 0 || b < 0 ) return -1;
    if( b != 0 ) return GCD(b,a%b);
    return a;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m; cin >> n >> m;
    vector<P> edge(m);
    rep(i,m) cin >> edge[i].second >> edge[i].first;
    sort(edge.begin(), edge.end());
    ll now = n, ans = 0;
    rep(i,n) {
        auto [c, a] = edge[i];
        if( GCD(now, a) == now ) continue;
        ans += c * GCD(now, a);
        now = GCD(now, a);
        if( now == 1 ) break;
    }
    cout << (now == 1 ? ans : -1) << endl;
    
    return 0;
}
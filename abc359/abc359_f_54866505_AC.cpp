/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc359/submissions/54866505
 * Submitted at: 2024-06-23 12:58:32
 * Problem URL: https://atcoder.jp/contests/abc359/tasks/abc359_f
 * Result: AC
 * Execution Time: 84 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    // 木の次数の合計は 2*(N-1) であることを利用しても解ける。天才
    ll n, ans = 0; cin >> n;
    vector<ll> a(n), deg(n, 1);
    priority_queue<P, vector<P>, greater<P>> pq;
    rep(i, n) {
        cin >> a[i];
        ans += a[i];
        pq.push(P(3*a[i], i));
    }
    
    ll time = n - 2; // 2*(N-1) - N 回分の操作を行う
    while(time--) {
        auto [val, idx] = pq.top(); pq.pop();
        ans += val;
        deg[idx]++;
        pq.push(P( (2*deg[idx]+1)*a[idx], idx));
    }
    cout << ans << '\n';
    
    return 0;
}
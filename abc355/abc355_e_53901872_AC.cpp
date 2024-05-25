/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc355/submissions/53901872
 * Submitted at: 2024-05-26 01:14:19
 * Problem URL: https://atcoder.jp/contests/abc355/tasks/abc355_e
 * Result: AC
 * Execution Time: 61 ms
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
    vector<vector<ll>> Graph((1LL << n) + 1);
    rep(i, (1LL << n) + 1) {
        ll cnt = 0;
        if( i == 0 ) cnt = n;
        else {
            ll tmp = i;
            while( tmp%2 == 0 ) {
                tmp /= 2;
                cnt++;
            }
        }
        reps(j, 0, cnt+1) {
            ll next = i + (1LL << j);
            if( next > (1LL << n) ) break;
            Graph[i].emplace_back(next);
            Graph[next].emplace_back(i);
        }
    }
    queue<P> q;
    q.push(P(l, -1));
    vector<ll> pre((1LL << n) + 1, -INF);
    while( !q.empty() ) {
        auto [v, p] = q.front(); q.pop();
        if( pre[v] != -INF ) continue;
        pre[v] = p;
        for( auto nv : Graph[v] ) {
            if( pre[nv] != -INF ) continue;
            q.push(P(nv, v));
        }
    }
    vector<P> ans;
    ll now = r+1;
    while( pre[now] != -1 ) {
        ans.emplace_back(P(pre[now], now));
        now = pre[now];
    }
    
    ll sum = 0;
    rep(i, ans.size()) {
        auto [a, b] = ans[i];
        ll mini = min(a,b), maxi = max(a,b);
        ll q1 = 0, q2 = 0, tmp = maxi - mini;
        while( tmp > 1 ) {
            tmp /= 2;
            q1++;
        }
        q2 = mini / pow(2,q1);
        cout << "? " << q1 << " " << q2 << endl;
        ll add; cin >> add;
        sum += ( a < b ? add : -add );
    }
    cout << "! " << (sum%100 + 100)%100 << endl;
    
    return 0;
}
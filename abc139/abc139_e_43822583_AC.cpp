/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc139/submissions/43822583
 * Submitted at: 2023-07-22 18:01:51
 * Problem URL: https://atcoder.jp/contests/abc139/tasks/abc139_e
 * Result: AC
 * Execution Time: 99 ms
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<vector<ll>> a(n,vector<ll>(n-1)), ok(n,vector<ll>(n,1e16));
    rep(i,n)rep(j,n-1) {
        cin >> a[i][j];
        a[i][j]--;
    }

    // battle : 今何回戦目か
    vector<ll> battle(n,0);
    queue<T> todo;
    rep(i,n) if( a[a[i][0]][0] == i ) todo.push( T(1, i, a[i][0]) );
    while( !todo.empty() ){
        auto [day, p1, p2] = todo.front(); todo.pop();
        if( ok[p1][p2] <= day ) continue;
        ok[p1][p2] = day;
        ok[p2][p1] = day;
        battle[p1]++;
        battle[p2]++;
        if( battle[p1] < n-1 && a[a[p1][battle[p1]]][battle[a[p1][battle[p1]]]] == p1 ){
            todo.push( T(day+1, p1, a[p1][battle[p1]]) );
        }
        if( battle[p2] < n-1 && a[a[p2][battle[p2]]][battle[a[p2][battle[p2]]]] == p2 ){
            todo.push( T(day+1, p2, a[p2][battle[p2]]) );
        }
    }
    ll ans = -1;
    rep(i,n){
        rep(j,n){
            if( i == j ) continue;
            if( ok[i][j] == 1e16 ) {
                cout << -1 << endl;
                return 0;
            }
            ans = max(ans,ok[i][j]);
        }
    }
    cout << ans << endl;
    
    return 0;
}
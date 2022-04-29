/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc187/submissions/31339092
 * Submitted at: 2022-04-29 16:20:15
 * Problem URL: https://atcoder.jp/contests/abc187/tasks/abc187_d
 * Result: AC
 * Execution Time: 122 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    ll n,takahashi = 0,aoki = 0,ans = 0; cin >> n;
    priority_queue<ll> todo;

    rep(i,n){
        ll a,b; cin >> a >> b;
        aoki += a;
        todo.push(2*a+b);
    }

    while(!todo.empty()){
        ll cost = todo.top(); todo.pop();
        takahashi += cost;
        ans++;
        if(takahashi > aoki)return cout << ans << endl,0;
    }

    return 0;
}
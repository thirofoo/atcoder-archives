/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc351/submissions/54690425
 * Submitted at: 2024-06-18 18:23:34
 * Problem URL: https://atcoder.jp/contests/abc351/tasks/abc351_c
 * Result: AC
 * Execution Time: 14 ms
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
    stack<ll> a;
    rep(i, n) {
        ll ele; cin >> ele;
        a.push(ele);
        while(a.size() > 1) {
            ll x = a.top(); a.pop();
            ll y = a.top(); a.pop();
            if(x == y) a.push(x+1);
            else {
                a.push(y);
                a.push(x);
                break;
            }
        }
    }
    cout << a.size() << endl;
    
    return 0;
}
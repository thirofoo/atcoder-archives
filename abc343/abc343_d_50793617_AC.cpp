/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc343/submissions/50793617
 * Submitted at: 2024-03-02 21:16:30
 * Problem URL: https://atcoder.jp/contests/abc343/tasks/abc343_d
 * Result: AC
 * Execution Time: 436 ms
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
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, t; cin >> n >> t;
    vector<ll> a(t), b(t);
    rep(i,t) {
        cin >> a[i] >> b[i];
        a[i]--;
    }
    set<ll> st1;
    multiset<ll> st2;
    vector<ll> player(n,0);
    st1.insert(0);
    rep(i,n) st2.insert(0);

    rep(i,t) {
        st2.erase(st2.find(player[a[i]]));
        if( st2.find(player[a[i]]) == st2.end() ) st1.erase(st1.find(player[a[i]]));
        player[a[i]] += b[i];
        st2.insert(player[a[i]]);
        st1.insert(player[a[i]]);
        cout << st1.size() << endl;
    }
    
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc347/submissions/51853934
 * Submitted at: 2024-03-30 22:01:56
 * Problem URL: https://atcoder.jp/contests/abc347/tasks/abc347_e
 * Result: AC
 * Execution Time: 131 ms
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
    
    ll n, q; cin >> n >> q;
    vector<ll> x(q);
    fenwick_tree<ll> fw(q);
    set<ll> st;
    vector<ll> a(n, 0), start(n,-1);
    rep(i,q) {
        cin >> x[i], x[i]--;
        if( !st.count(x[i]) ) {
            start[x[i]] = i;
            st.insert(x[i]);
        }
        else {
            a[x[i]] += fw.sum(start[x[i]], i);
            start[x[i]] = -1;
            st.erase(st.find(x[i]));
        }
        fw.add(i, st.size());
    }
    rep(i,n) {
        if( start[i] != -1 ) a[i] += fw.sum(start[i], q);
        cout << a[i] << " ";
    }
    cout << endl;
    
    return 0;
}
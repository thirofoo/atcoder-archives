/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc355/submissions/53825700
 * Submitted at: 2024-05-25 21:01:07
 * Problem URL: https://atcoder.jp/contests/abc355/tasks/abc355_a
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
    
    ll a, b; cin >> a >> b;
    set<ll> st;
    st.insert(a);
    st.insert(b);
    if( st.size() == 1 ) cout << -1 << endl;
    else {
        reps(i,1,4) {
            if( st.find(i) == st.end() ) {
                cout << i << endl;
                break;
            }
        }
    }
    
    return 0;
}
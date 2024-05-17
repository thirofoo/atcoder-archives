/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc145/submissions/53548661
 * Submitted at: 2024-05-17 18:03:57
 * Problem URL: https://atcoder.jp/contests/abc145/tasks/abc145_d
 * Result: AC
 * Execution Time: 6 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll x, y; cin >> x >> y;
    vector<mint> fact(1e6+1,1);
    for(int i=1; i<=1e6; i++) fact[i] = fact[i-1]*i;

    ll num_2_1 = -1, num_1_2 = -1;
    reps(i,0,1e6) {
        ll nx = x - 2*i, ny = y - i;
        if(nx < 0 || ny < 0) break;
        if(nx*2 == ny) {
            num_2_1 = i;
            num_1_2 = nx;
            break;
        }
    }
    if(num_2_1 == -1) {
        cout << 0 << endl;
        return 0;
    }
    cout << (fact[num_2_1+num_1_2] / fact[num_2_1] / fact[num_1_2]).val() << endl;
    
    return 0;
}
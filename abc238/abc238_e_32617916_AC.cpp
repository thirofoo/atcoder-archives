/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc238/submissions/32617916
 * Submitted at: 2022-06-20 13:38:49
 * Problem URL: https://atcoder.jp/contests/abc238/tasks/abc238_e
 * Result: AC
 * Execution Time: 44 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n,q; cin >> n >> q;
    dsu uf(n+1);
    while(q--){
        int l,r; cin >> l >> r;
        l--; r--;
        uf.merge(l,r+1);
    }
    if(uf.same(0,n))cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
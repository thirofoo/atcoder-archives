/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/tenka1-2018/submissions/48499940
 * Submitted at: 2023-12-15 09:43:33
 * Problem URL: https://atcoder.jp/contests/tenka1-2018/tasks/tenka1_2018_d
 * Result: WA
 * Execution Time: 11 ms
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
    for(ll i=1; i*(i+1)/2<=n; i++) {
        if( i*(i+1)/2 == n ) {
            cout << "Yes\n";
            cout << n << '\n';
            ll cnt = 1;
            vector<vector<ll>> edge(i+1,vector<ll>{});
            rep(j,i+1) for(ll k=j+1; k<i+1; k++){
                edge[j].emplace_back(cnt);
                edge[k].emplace_back(cnt);
                cnt++;
            }
            for(auto v:edge) {
                cout << v.size() << " ";
                for(auto ele:v) cout << ele << " ";
                cout << '\n';
            }
            return 0;
        }
    }
    cout << "No\n";
    
    return 0;
}

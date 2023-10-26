/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/adt_all_20231026_2/submissions/46944135
 * Submitted at: 2023-10-26 18:50:53
 * Problem URL: https://atcoder.jp/contests/adt_all_20231026_2/tasks/abc221_c
 * Result: AC
 * Execution Time: 13 ms
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
    
    string n; cin >> n;
    ll dig = log10(stoll(n))+1, ans = -1;
    rep(i,(1ll << dig)) {
        vector<ll> e1, e2;
        rep(j,dig) {
            if( i & (1 << j) ) e1.emplace_back(n[j]-'0');
            else e2.emplace_back(n[j]-'0');
        }
        sort(e1.begin(), e1.end());
        reverse(e1.begin(), e1.end());
        sort(e2.begin(), e2.end());
        reverse(e2.begin(), e2.end());
        if( e1.empty() || e2.empty() ) continue;
        ll v1 = 0, v2 = 0;
        rep(j,e1.size()) {
            v1 *= 10;
            v1 += e1[j];
            cerr << e1[j] << " ";
        }
        cerr << endl;
        rep(j,e2.size()) {
            v2 *= 10;
            v2 += e2[j];
            cerr << e2[j] << " ";
        }
        cerr << endl;
        cerr << v1 << " " << v2 << endl;
        ans = max(ans, v1*v2);
    }
    cout << ans << endl;
    
    return 0;
}
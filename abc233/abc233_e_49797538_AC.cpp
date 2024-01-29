/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc233/submissions/49797538
 * Submitted at: 2024-01-30 02:36:16
 * Problem URL: https://atcoder.jp/contests/abc233/tasks/abc233_e
 * Result: AC
 * Execution Time: 20 ms
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
    
    string x; cin >> x;
    ll now = 0;
    rep(i,x.size()) now += x[i]-'0';
    reverse(x.begin(), x.end());
    vector<ll> ans(x.size()+100, 0);
    rep(i,x.size()) {
        ll tmp = now + ans[i], idx = i;
        ans[i] = 0;
        while( tmp != 0 ) {
            ans[idx] += tmp%10;
            tmp /= 10;
            idx++;
        }
        now -= x[i]-'0';
    }
    reverse(ans.begin(), ans.end());
    bool f = false;
    rep(i,ans.size()) {
        f |= (ans[i] != 0);
        if( f ) cout << ans[i];
    }
    cout << endl;

    return 0;
}
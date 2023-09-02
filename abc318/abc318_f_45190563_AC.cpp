/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc318/submissions/45190563
 * Submitted at: 2023-09-02 22:32:41
 * Problem URL: https://atcoder.jp/contests/abc318/tasks/abc318_f
 * Result: AC
 * Execution Time: 328 ms
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
    vector<ll> x(n), l(n);
    rep(i,n) cin >> x[i];
    rep(i,n) cin >> l[i];
    vector<ll> b_cand;
    rep(i,n) {
        rep(j,n) {
            b_cand.emplace_back(x[i]+l[j]);
            b_cand.emplace_back(x[i]-l[j]);
        }
    }
    sort(b_cand.begin(), b_cand.end());
    b_cand.erase(unique(b_cand.begin(), b_cand.end()), b_cand.end());

    ll ans = 0;
    set<ll> st;
    rep(i,b_cand.size()-1) {
        ll left = b_cand[i], right = b_cand[i+1]-1;
        vector<ll> rest, need;
        rep(j,n) rest.emplace_back(l[j]);
        rep(j,n) need.emplace_back(max(abs(x[j]-left), abs(x[j]-right)));
        sort(rest.begin(), rest.end());
        sort(need.begin(), need.end());
        bool f = true;
        rep(j,n) {
            if( rest[j] < need[j] ) {
                f = false;
                break;
            }
        }
        
        if( f ) {
            cerr << left << " " << right << endl;
            ans += right-left+1;
            st.insert(left);
        }
    }

    rep(i,b_cand.size()) {
        ll b = b_cand[i];
        if( st.count(b) ) continue;

        vector<ll> rest, need;
        rep(j,n) rest.emplace_back(l[j]);
        rep(j,n) need.emplace_back(abs(x[j]-b));
        sort(rest.begin(), rest.end());
        sort(need.begin(), need.end());
        bool f = true;
        rep(j,n) {
            if( rest[j] < need[j] ) {
                f = false;
                break;
            }
        }
        if( f ) ans++;
    }
    cout << ans << endl;
    
    return 0;
}
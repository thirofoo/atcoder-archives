/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc321/submissions/45838893
 * Submitted at: 2023-09-23 21:23:39
 * Problem URL: https://atcoder.jp/contests/abc321/tasks/abc321_c
 * Result: AC
 * Execution Time: 1 ms
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
    
    ll k; cin >> k;
    vector<ll> a;
    set<ll> st;
    auto dfs = [&](auto self, ll now) -> void {
        if( st.count(now) ) return;
        a.emplace_back(now);
        st.insert(now);
        for(ll i=0;i<now%10;i++) {
            if( st.count(10*now+i) ) continue;
            self(self, 10*now+i);
        }
    };
    for(ll i=1;i<=9;i++) dfs(dfs, i);
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    cout << a[k-1] << endl;
    
    return 0;
}
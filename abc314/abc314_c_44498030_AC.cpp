/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc314/submissions/44498030
 * Submitted at: 2023-08-12 21:12:38
 * Problem URL: https://atcoder.jp/contests/abc314/tasks/abc314_c
 * Result: AC
 * Execution Time: 213 ms
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
    
    ll n,m; string s; cin >> n >> m >> s;
    vector<ll> c(n);
    vector<deque<ll>> color(m+1);
    rep(i,n) {
        cin >> c[i];
        color[c[i]].push_back(i);
    }
    rep(i,m+1) {
        if( color[i].empty() ) continue;
        color[i].push_front(color[i].back());
        color[i].pop_back();
    }
    rep(i,n) {
        cout << s[color[c[i]].front()];
        color[c[i]].pop_front();
    }
    cout << endl;
    
    return 0;
}
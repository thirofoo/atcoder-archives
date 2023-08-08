/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc165/submissions/44376020
 * Submitted at: 2023-08-08 10:59:38
 * Problem URL: https://atcoder.jp/contests/abc165/tasks/abc165_e
 * Result: AC
 * Execution Time: 144 ms
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
    
    ll n, m; cin >> n >> m;
    // P(N,1) は 間0個 or 間N-2個 と同義
    // → 制約的に 間 0 ~ N/2 個のペアでないと一周回ってダメになってしまう
    // → かなりきつきつに埋めないとダメなことに気付くのが point
    ll start_even = 0, start_odd = (m-m/2)*2;
    vector<P> ans;
    for(ll i=m-1;i>=0;i--) {
        if(i%2 == 0) {
            ans.push_back(P(start_even+1, start_even+i+2));
            start_even++;
        }
        else {
            ans.push_back(P(start_odd+1, start_odd+i+2));
            start_odd++;
        }
    }
    for(auto [e1,e2]:ans) cout << e1 << " " << e2 << endl;
    
    return 0;
}
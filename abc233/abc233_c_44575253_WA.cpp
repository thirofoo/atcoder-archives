/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc233/submissions/44575253
 * Submitted at: 2023-08-14 09:54:51
 * Problem URL: https://atcoder.jp/contests/abc233/tasks/abc233_c
 * Result: WA
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
    
    ll n,x; cin >> n >> x;
    vector<vector<ll>> a;
    rep(i,n) {
        ll l; cin >> l;
        vector<ll> tmp(l);
        rep(j,l) cin >> tmp[j];
        a.push_back(tmp);
    }
    map<__int128_t,ll> memo1,memo2;
    rep(i,a[0].size()) memo1[a[0][i]]++;
    for(ll i=1;i<n;i++) {
        for(auto [key,value]:memo1) {
            rep(j,a[i].size()) {
                if( key*a[i][j] > (__int128_t)x ) continue;
                memo2[key*a[i][j]] += memo1[key];
            }
        }
        swap(memo1,memo2);
    }
    // for(auto [key,value]:memo1) cout << key << " : " << value << endl;
    cout << memo1[x] << endl;
    
    return 0;
}
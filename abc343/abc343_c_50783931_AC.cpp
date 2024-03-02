/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc343/submissions/50783931
 * Submitted at: 2024-03-02 21:08:15
 * Problem URL: https://atcoder.jp/contests/abc343/tasks/abc343_c
 * Result: AC
 * Execution Time: 38 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> r_all;
    reps(i,1,1000001) {
        ll r = i*i*i;
        string s = to_string(r);
        bool flag = true;
        rep(i,s.size()) flag &= (s[i] == s[s.size()-i-1]);
        if( flag ) r_all.emplace_back(r);
    }
    auto itr = upper_bound(r_all.begin(), r_all.end(), n);
    itr--;
    cout << *itr << endl;
    
    return 0;
}
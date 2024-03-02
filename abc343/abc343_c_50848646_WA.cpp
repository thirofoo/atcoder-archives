/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc343/submissions/50848646
 * Submitted at: 2024-03-02 23:39:52
 * Problem URL: https://atcoder.jp/contests/abc343/tasks/abc343_c
 * Result: WA
 * Execution Time: 85 ms
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

string solve_rs(ll n) {
    ll nn = cbrt(n);
    while (1)
    {
        ll nnn=nn*nn*nn;
        string count=to_string(nnn);
        string a=count;
        reverse(a.begin(),a.end());
        if(a==count) return a;
        else nn--;
    }
}

vector<ll> r_all;
ll solve_thiro(ll n) {
    auto itr = upper_bound(r_all.begin(), r_all.end(), n); itr--;
    return *itr;
    // cout << *itr << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    reps(i,1,1000001) {
        ll r = i*i*i;
        string s = to_string(r);
        bool flag = true;
        rep(i,s.size()) flag &= (s[i] == s[s.size()-i-1]);
        if( flag ) r_all.emplace_back(r);
    }

    ll n; cin >> n;
    cout << solve_rs(n) << endl;
    
    // reps(i,0,1000000) {
    //     ll ans_rs = stoll(solve_rs(i));
    //     ll ans_thiro = solve_thiro(i);
    //     if( i%100000 == 0 ) cerr << "i: " << i << endl;
    //     if( ans_rs != ans_thiro ) {
    //         cout << "ans_rs: " << ans_rs << endl;
    //         cout << "ans_thiro: " << ans_thiro << endl;
    //         break;
    //     }
    // }
    
    return 0;
}
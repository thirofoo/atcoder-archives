/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc122/submissions/50679348
 * Submitted at: 2024-02-27 17:57:55
 * Problem URL: https://atcoder.jp/contests/abc122/tasks/abc122_d
 * Result: AC
 * Execution Time: 4 ms
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
using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    const vector<char> c = {'A', 'G', 'C', 'T'};
    const ll size = 4;
    auto containAGC = [&](string &s) { return s.find("AGC") != string::npos; };
    auto check = [&](string &s) {
        bool res = containAGC(s);
        rep(i,3) {
            string ts = s;
            swap(ts[i], ts[i+1]);
            res |= containAGC(ts);
        }
        return res;
    };

    map<string, mint> dp;
    dp["###"] = 1;
    // 前 3 文字が分かればよい ⇒ map で NextDP がスマート
    while( n-- ) {
        map<string, mint> ndp;
        for(auto [pre, v]:dp) {
            rep(j,size) {
                string s = pre + c[j];
                if( !check(s) ) ndp[s.substr(1,3)] += v;
            }
        }
        swap(dp, ndp);
    }
    mint ans = 0;
    for(auto [_, v]:dp) ans += v;
    cout << ans.val() << endl;
    
    return 0;
}
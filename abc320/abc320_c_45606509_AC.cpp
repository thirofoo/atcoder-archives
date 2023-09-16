/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc320/submissions/45606509
 * Submitted at: 2023-09-16 21:26:12
 * Problem URL: https://atcoder.jp/contests/abc320/tasks/abc320_c
 * Result: AC
 * Execution Time: 3 ms
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
    
    ll m; string s1, s2, s3; cin >> m >> s1 >> s2 >> s3;
    ll ans = 1e9;
    rep(i,m) {
        rep(j,m) {
            rep(k,m) {
                if( s1[i] != s2[j] || s2[j] != s3[k] || s1[i] != s3[k] ) continue;
                vector<ll> p(3,0), ele;
                ele.push_back(i);
                ele.push_back(j);
                ele.push_back(k);
                iota(p.begin(), p.end(), 0);
                do {
                    ll cand = ele[p[0]];
                    rep(l,2) {
                        cand += (ele[p[l+1]] - ele[p[l]] + m) % m;
                        if( ele[p[l]] == ele[p[l+1]] ) cand += m;
                    }
                    ans = min(ans, cand);
                }while(next_permutation(p.begin(), p.end()));
            }
        }
    }
    cout << (ans == 1e9 ? -1 : ans) << endl;
    
    return 0;
}
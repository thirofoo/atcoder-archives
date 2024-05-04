/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc352/submissions/53129507
 * Submitted at: 2024-05-04 22:12:04
 * Problem URL: https://atcoder.jp/contests/abc352/tasks/abc352_f
 * Result: WA
 * Execution Time: 2210 ms
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

namespace utility {
    struct timer {
        chrono::system_clock::time_point start;
        // 開始時間を記録
        void CodeStart() {
            start = chrono::system_clock::now();
        }
        // 経過時間 (ms) を返す
        double elapsed() const {
        using namespace std::chrono;
            return (double)duration_cast<milliseconds>(system_clock::now() - start).count();
        }
    } mytm;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    utility::mytm.CodeStart();
    
    ll n, m; cin >> n >> m;
    vector<ll> a(m), b(m), c(m);
    rep(i,m) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
    }

    if( m < n/2 - 1 ) {
        rep(i,n) cout << -1 << " ";
        cout << endl;
        return 0;
    }
    else {
        ll cnt = 1;
        while( cnt++ );
    }

    // 1. 連結成分の順列全探索をすれば行けるのでは？


    vector<ll> p(n);
    vector<vector<bool>> g(n ,vector(n,false));
    iota(p.begin(), p.end(), 0);
    do {
        bool f = true;
        rep(i,m) {
            f &= ( p[a[i]] - p[b[i]] == c[i] );
            if( !f ) break;
        }
        if( f ) rep(i,n) g[i][p[i]] = true;
    } while( next_permutation(p.begin(), p.end()) );

    vector<ll> ans(n, -1);
    rep(j,n) {
        vector<ll> cand;
        rep(i,n) if( g[i][j] ) cand.emplace_back(i);
        if( cand.size() == 1 ) ans[cand[0]] = j+1;
    }
    rep(i,n) cout << ans[i] << " ";
    cout << endl;
    
    return 0;
}
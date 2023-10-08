/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc166/submissions/46380294
 * Submitted at: 2023-10-08 21:31:03
 * Problem URL: https://atcoder.jp/contests/arc166/tasks/arc166_a
 * Result: AC
 * Execution Time: 110 ms
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
    
    ll t; cin >> t;
    while( t-- ) {
        ll n; string x, y; cin >> n >> x >> y;
        bool flag = false;
        vector<string> s1, s2;
        string ts1 = "", ts2 = "";
        rep(i,n) {
            if( y[i] == 'C' && x[i] != 'C' ) {
                flag = true;
                break;
            }
            if( y[i] == 'C' && x[i] == 'C' ) {
                s1.emplace_back(ts1);
                s2.emplace_back(ts2);
                ts1 = "", ts2 = "";
            }
            else {
                ts1 += x[i];
                ts2 += y[i];
            }
        }
        if( ts1 != "" ) {
            s1.emplace_back(ts1);
            s2.emplace_back(ts2);
        }

        if( flag ) {
            cout << "No" << endl;
            continue;
        }

        bool f = true;
        rep(i,s1.size()) {
            ts1 = s1[i], ts2 = s2[i];
            cerr << ts1 << " " << ts2 << endl;

            vector<ll> c1(3,0), c2(3,0), i1, i2;
            rep(j,ts1.size()) {
                c1[ts1[j]-'A']++;
                c2[ts2[j]-'A']++;
                if( ts1[j] == 'A' ) i1.emplace_back(j);
                if( ts2[j] == 'A' ) i2.emplace_back(j);
            }
            if( max(c1[0],c2[0]) > min(c1[0]+c1[2],c2[0]+c2[2]) ) {
                f = false;
                break;
            }
            ll cnt = max(c1[0],c2[0]);
            rep(j,n) {
                if( c1[0] == cnt ) break;
                if( ts1[j] == 'C' ) {
                    i1.emplace_back(j);
                    c1[0]++;
                }
            }
            for(ll j=n-1;j>=0;j--) {
                if( c2[0] == cnt ) break;
                if( ts2[j] == 'C' ) {
                    i2.emplace_back(j);
                    c2[0]++;
                }
            }
            sort(i1.begin(), i1.end());
            sort(i2.begin(), i2.end());
            rep(j,i1.size()) f &= (i1[j] <= i2[j]);
        }
        cout << ( f ? "Yes" : "No" ) << endl;
    }
    
    return 0;
}
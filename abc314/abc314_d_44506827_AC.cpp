/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc314/submissions/44506827
 * Submitted at: 2023-08-12 21:26:49
 * Problem URL: https://atcoder.jp/contests/abc314/tasks/abc314_d
 * Result: AC
 * Execution Time: 52 ms
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
    
    ll n,q; string s; cin >> n >> s >> q;

    bool up = false;
    int swi = -1;
    vector<ll> turn(n,0);
    rep(i,q) {
        ll t,x; char c; cin >> t >> x >> c;
        x--;
        if( t == 1 ) {
            s[x] = c;
            turn[x] = i+1;
        }
        else if( t == 2 ) {
            up = false;
            swi = i+1;
        }
        else {
            up = true;
            swi = i+1;
        }
    }
    if( swi == -1 ) cout << s << endl;
    else {
        string ans = "";
        if( up ) {
            rep(i,n) {
                if( turn[i] > swi ) ans += s[i];
                else ans += toupper(s[i]);
            }
        }
        else { 
            rep(i,n) {
                if( turn[i] > swi ) ans += s[i];
                else ans += tolower(s[i]);
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}
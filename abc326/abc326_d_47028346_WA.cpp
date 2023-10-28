/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc326/submissions/47028346
 * Submitted at: 2023-10-28 21:47:30
 * Problem URL: https://atcoder.jp/contests/abc326/tasks/abc326_d
 * Result: WA
 * Execution Time: 136 ms
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
    
    ll n; string r, c; cin >> n >> r >> c;
    vector<string> s(n,".....");

    vector<int> p1(n);
    iota(p1.begin(), p1.end(), 0);
    do {
        vector<int> p2(n);
        iota(p2.begin(), p2.end(), 0);
        do {
            vector<int> p3(n);
            iota(p3.begin(), p3.end(), 0);
            do {
                vector<string> cand(n,".....");
                bool f = true;
                rep(i,n) {
                    rep(j,n) {
                        ll cnt = 0;
                        if( p1[i] == j ) {
                            cand[i][j] = 'A';
                            cnt++;
                        }
                        if( p2[i] == j ) {
                            cand[i][j] = 'B';
                            cnt++;
                        }
                        if( p3[i] == j ) {
                            cand[i][j] = 'C';
                            cnt++;
                        }
                        if( cnt > 1 ) {
                            f = false;
                            break;
                        }
                    }
                    if( !f ) break;
                }
                if( !f ) continue;
                string s1 = "", s2 = "";
                vector<ll> ac1(n,0), bc1(n,0), cc1(n,0), ac2(n,0), bc2(n,0), cc2(n,0);
                rep(i,n) {
                    ll cc = 0;
                    rep(j,n) {
                        if( cc == 0 && cand[i][j] != '.' ) {
                            s1 += cand[i][j];
                            cc++;
                        }
                        
                        if( cand[i][j] == 'A' ) ac1[i]++;
                        else if( cand[i][j] == 'B' ) bc1[i]++;
                        else if( cand[i][j] == 'C' ) cc1[i]++;
                    }
                    f &= (cc == 1);
                }
                rep(j,n) {
                    ll cc = 0;
                    rep(i,n) {
                        if( cc == 0 && cand[i][j] != '.' ) {
                            s2 += cand[i][j];
                            cc++;
                        }

                        if( cand[i][j] == 'A' ) ac2[j]++;
                        else if( cand[i][j] == 'B' ) bc2[j]++;
                        else if( cand[i][j] == 'C' ) cc2[j]++;
                    }
                    f &= (cc == 1);
                }
                f &= (s1 == r && s2 == c);
                rep(i,n) f &= (ac1[i] == 1 && bc1[i] == 1 && cc1[i] == 1 && ac2[i] == 1 && bc2[i] == 1 && cc2[i] == 1);

                if( f ) {
                    cout << "Yes" << endl;
                    rep(i,n) cout << cand[i] << endl;
                    return 0;
                }
            }while(next_permutation(p3.begin(), p3.end()));
        } while(next_permutation(p2.begin(), p2.end()));
    } while(next_permutation(p1.begin(), p1.end()));

    cout << "No" << endl;
    
    return 0;
}
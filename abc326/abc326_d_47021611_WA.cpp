/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc326/submissions/47021611
 * Submitted at: 2023-10-28 21:32:53
 * Problem URL: https://atcoder.jp/contests/abc326/tasks/abc326_d
 * Result: WA
 * Execution Time: 116 ms
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
                rep(i,n) {
                    rep(j,n) {
                        if( cand[i][j] != '.' ) {
                            s1 += cand[i][j];
                            break;
                        }
                    }
                }
                rep(j,n) {
                    rep(i,n) {
                        if( cand[i][j] != '.' ) {
                            s2 += cand[i][j];
                            break;
                        }
                    }
                }
                f &= (s1 == r && s2 == c);
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
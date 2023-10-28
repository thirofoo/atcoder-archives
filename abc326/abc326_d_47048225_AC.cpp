/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc326/submissions/47048225
 * Submitted at: 2023-10-29 00:26:41
 * Problem URL: https://atcoder.jp/contests/abc326/tasks/abc326_d
 * Result: AC
 * Execution Time: 240 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; string r, c; cin >> n >> r >> c;
    vector<int> p1(n), p2(n), p3(n);
    iota(p1.begin(), p1.end(), 0);
    iota(p2.begin(), p2.end(), 0);
    iota(p3.begin(), p3.end(), 0);
    do {
        do {
            do {
                vector<string> cand(n,".....");
                bool f = true;
                rep(i,n) f &= !(p1[i] == p2[i] || p2[i] == p3[i] || p1[i] == p3[i]);
                rep(i,n) rep(j,n) {
                    ll cnt = 0;
                    if( p1[i] == j ) cand[i][j] = 'A';
                    if( p2[i] == j ) cand[i][j] = 'B';
                    if( p3[i] == j ) cand[i][j] = 'C';
                }
                if( !f ) continue;
                string s1 = "", s2 = "";
                rep(i,n) rep(j,n) {
                    if( cand[i][j] != '.' ) {
                        s1 += cand[i][j];
                        break;
                    }
                }
                rep(j,n) rep(i,n) {
                    if( cand[i][j] != '.' ) {
                        s2 += cand[i][j];
                        break;
                    }
                }
                f &= (s1 == r && s2 == c);
                if( f ) {
                    cout << "Yes" << endl;
                    rep(i,n) {
                        rep(j,n) cout << cand[i][j];
                        cout << endl;
                    }
                    return 0;
                }
            }while(next_permutation(p3.begin(), p3.end()));
        } while(next_permutation(p2.begin(), p2.end()));
    } while(next_permutation(p1.begin(), p1.end()));

    cout << "No" << endl;
    
    return 0;
}
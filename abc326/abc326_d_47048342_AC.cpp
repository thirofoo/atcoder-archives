/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc326/submissions/47048342
 * Submitted at: 2023-10-29 00:32:40
 * Problem URL: https://atcoder.jp/contests/abc326/tasks/abc326_d
 * Result: AC
 * Execution Time: 75 ms
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
    vector<string> cand;
    string first = "";
    rep(i,n) first += ".";
    iota(p1.begin(), p1.end(), 0), p2 = p1, p3 = p1;
    do {
        do {
            do {
                cand.assign(n,first);
                bool f = true;
                rep(i,n) f &= !(p1[i] == p2[i] || p2[i] == p3[i] || p1[i] == p3[i]);
                if( !f ) continue;
                rep(i,n) rep(j,n) {
                    if( p1[i] == j ) cand[i][j] = 'A';
                    if( p2[i] == j ) cand[i][j] = 'B';
                    if( p3[i] == j ) cand[i][j] = 'C';
                }
                string s1 = "", s2 = "";
                rep(i,n) rep(j,n) if( cand[i][j] != '.' && s1.size() <= i ) s1 += cand[i][j];
                rep(j,n) rep(i,n) if( cand[i][j] != '.' && s2.size() <= j ) s2 += cand[i][j];
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
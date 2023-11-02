/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc055/submissions/47166760
 * Submitted at: 2023-11-03 08:05:25
 * Problem URL: https://atcoder.jp/contests/abc055/tasks/arc069_b
 * Result: AC
 * Execution Time: 4 ms
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
    
    // 2個を仮定すれば他は全部決まる
    ll n; string s; cin >> n >> s;
    map<char,char> rev = {{'S','W'},{'W','S'}};
    rep(i,4) {
        string cand = "";
        cand += (i/2 ? 'S' : 'W');
        cand += (i%2 ? 'S' : 'W');
        for(int i=1; i<n-1; i++) {
            if( cand[i] == 'S' ) cand += (s[i] == 'o' ? cand[i-1] : rev[cand[i-1]]);
            else cand += (s[i] == 'o' ? rev[cand[i-1]] : cand[i-1]);
        }
        bool f = true;
        if( (cand[0] == 'W' && s[0] == 'o') || (cand[0] == 'S' && s[0] == 'x') ) f &= (cand[1] != cand[n-1]);
        else f &= (cand[1] == cand[n-1]);
        if( (cand[n-1] == 'W' && s[n-1] == 'o') || (cand[n-1] == 'S' && s[n-1] == 'x') ) f &= (cand[0] != cand[n-2]);
        else f &= (cand[0] == cand[n-2]);
        if( f ) return cout << cand << '\n', 0;
    }
    cout << -1 << '\n';
    
    return 0;
}
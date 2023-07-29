/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc055/submissions/44019654
 * Submitted at: 2023-07-29 10:28:11
 * Problem URL: https://atcoder.jp/contests/abc055/tasks/arc069_b
 * Result: WA
 * Execution Time: 8 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 最初の2匹全探索で行けそう
    ll n; string s; cin >> n >> s;
    rep(i,4) {
        string cand = "";
        char first = ((i & 1) ? 'S' : 'W'), first_ch = first;
        char second = ((i & 2) ? 'S' : 'W');
        cand += first;
        cand += second;
        for(int j=2;j<n;j++){
            if( (s[j-1] == 'x' && second == 'S') || s[j-1] == 'o' && second == 'W' ) first = ( first == 'S' ? 'W' : 'S' );
            swap(first, second);
            cand += second;
        }
        if( (s[n-1] == 'x' && second == 'S') || s[n-1] == 'o' && second == 'W' ) second = ( first == 'S' ? 'W' : 'S' );
        else second = first;
        if( second == first_ch ) return cout << cand << endl,0;
    }
    cout << -1 << endl;
    
    return 0;
}
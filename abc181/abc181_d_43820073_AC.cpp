/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc181/submissions/43820073
 * Submitted at: 2023-07-22 16:21:27
 * Problem URL: https://atcoder.jp/contests/abc181/tasks/abc181_d
 * Result: AC
 * Execution Time: 9 ms
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
    
    string s; cin >> s;
    vector<ll> cnt(10,0);
    rep(i,s.size()) cnt[s[i]-'0']++;

    rep(i,( s.size() <= 2 ? pow(10,(int)s.size()) : 1000) ){
        if( i%8 != 0 ) continue;
        bool f = true;
        ll now = i;
        
        rep(j, min(3ll, (ll)s.size())) {
            // f &= (cnt[now%10]);
            // ※ 実はこれだと f が int にキャスとされて、1 & cnt[now%10] の bit演算になる
            // → bool値としてうまく更新されない。。

            f &= (cnt[now%10] > 0);
            cnt[now%10]--;
            now /= 10;
        }
        if( f ) return cout << "Yes" << endl, 0;
        now = i;
        rep(j, min(3ll, (ll)s.size())) {
            cnt[now%10]++;
            now /= 10;
        }
    }
    cout << "No" << endl;
    
    return 0;
}
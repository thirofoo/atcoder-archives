/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc055/submissions/47142636
 * Submitted at: 2023-11-02 02:16:02
 * Problem URL: https://atcoder.jp/contests/agc055/tasks/agc055_a
 * Result: WA
 * Execution Time: 86 ms
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

//セグ木状に乗せる型。
using S = ll;
S op(S a,S b){return a+b;} // operator(作用素)
S e(){return 0ll;} // 単位元 (op(e,a) = a)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 境界1つ全探索 ⇒ segment tree 上で二分探索 (これを最大6回) (計算量微妙)
    // と思ったが、ABCの並べ方全探索 ⇒ 最大になるように分解 を繰り返すと実は6回で行けそう
    ll n, cnt = 0, turn = 1; string s; cin >> n >> s;
    vector<ll> ans(3*n,-1), p(3), best;
    iota(p.begin(), p.end(), 0);
    while( cnt != 3*n ) {
        ll max_len = 0;
        do {
            ll pi = 0, time = 0, idx = 0, mini = 1e9;
            rep(i,3*n) {
                if( ans[i] != -1 ) continue;
                if( pi != 3 && s[i] == 'A'+p[pi] ) time++;
                idx++;
                if( idx == (3*n-cnt)/3 ) {
                    mini = min(mini, time);
                    time = 0, idx = 0;
                    pi++;
                }
            }
            if( max_len < mini ) {
                max_len = mini;
                best = p;
            }
        } while(next_permutation(p.begin(), p.end()));
        ll pi = 0, time = 0;
        rep(i,3*n) {
            if( ans[i] != -1 ) continue;
            if( pi != 3 && s[i] == 'A'+best[pi] ) time++, cnt++, ans[i] = turn;
            if( time == max_len ) {
                time = 0;
                pi++;
            }
        }
        turn++;
    }
    rep(i,3*n) cout << ans[i];
    cout << endl;
    
    return 0;
}
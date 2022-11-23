/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc278/submissions/36737231
 * Submitted at: 2022-11-23 18:46:25
 * Problem URL: https://atcoder.jp/contests/abc278/tasks/abc278_f
 * Result: AC
 * Execution Time: 54 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
template<class T, class... Ts> void print(const T& a, const Ts&... b){cout << a;(cout << ... << (cout << ' ', b));cout << '\n';}
template<class... T> void input(T&... a){(cin >> ... >> a);}
void print(){cout << '\n';}
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // bitDP ver (再起の方が分かり易いし書きやすい)
    // 最適な行動を取る時は帰りがけ(dpなら貰うdp)。

    // Point:
    // 状態iの文字列しか使わない時の勝敗を求めるdpをする!(区間dpっぽい)
    ll n; input(n);
    vector<string> s(n);
    rep(i,n)input(s[i]);
    // dp[i][j] : 全部でiの文字列を使い、最後にjを使ったときの勝敗
    vector<vector<bool>> dp((1LL << n),vector<bool>(n,false));
    rep(i,(1LL << n)){
        rep(j,n){
            if(!(i & (1LL << j)))continue;

            // 前の文字列として有り得るものを全探索
            rep(k,n){
                if(j == k || !(i & (1LL << k)) || s[j][0] != s[k].back())continue;
                dp[i][j] = (dp[i][j] || !dp[i^(1LL << j)][k] ? 1 : 0);
            }
        }
    }

    // nの偶奇で勝敗を考える(nが奇数の時は先手,偶数の時は後手の勝敗を述べている為)
    bool f = false;
    rep(i,n)f |= (dp[(1LL << n)-1][i])^(n%2+1);
    print((f ? "First" : "Second"));
    
    return 0;
}
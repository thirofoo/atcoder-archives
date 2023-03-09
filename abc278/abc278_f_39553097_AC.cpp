/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc278/submissions/39553097
 * Submitted at: 2023-03-09 16:54:46
 * Problem URL: https://atcoder.jp/contests/abc278/tasks/abc278_f
 * Result: AC
 * Execution Time: 52 ms
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
    
    ll n; input(n);
    vector<string> s(n);
    rep(i,n)input(s[i]);

    // dp : trueなら先手勝利、falsなら後手勝利
    vector dp((1LL << n),vector<bool>(n,false));
    for(ll i=1;i<(1LL << n);i++){
        rep(j,n){
            bool f = false;
            if(!(i & (1LL << j)))continue;
            rep(l,n){
                if(l == j)continue;
                if(i & (1LL << l) && s[j][0] == s[l].back()){
                    f |= dp[i^(1LL << j)][l];
                }
            }
            dp[i][j] = !f;
        }
    }
    bool ans = false;
    rep(i,n)ans |= dp[(1LL << n)-1][i];
    print(ans ? "First" : "Second");
    
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc164/submissions/36912718
 * Submitted at: 2022-12-01 19:52:17
 * Problem URL: https://atcoder.jp/contests/abc164/tasks/abc164_d
 * Result: AC
 * Execution Time: 776 ms
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
    
    string s; input(s);
    vector<ll> dp(2019,0),ndp;
    ll ans = 0;
    rep(i,s.size()){
        ndp.assign(2019,0);
        ndp[s[i]-'0']++;
        ans += dp[0];
        rep(j,2019){
            ll tmp = (j*10 + (s[i]-'0'))%2019;
            ndp[tmp] += dp[j];
        }
        swap(dp,ndp);
    }
    print(ans+dp[0]);
    
    return 0;
}
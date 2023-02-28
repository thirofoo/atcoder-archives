/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc234/submissions/39305125
 * Submitted at: 2023-02-28 12:52:57
 * Problem URL: https://atcoder.jp/contests/abc234/tasks/abc234_f
 * Result: TLE
 * Execution Time: 2205 ms
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
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string s; input(s);
    vector<ll> num(26,0);
    rep(i,s.size())num[s[i]-'a']++;
    vector<mint> kaizyo(s.size()+1,0);
    kaizyo[0] = 1;
    for(int i=1;i<=s.size();i++)kaizyo[i] = kaizyo[i-1]*i;
    vector<vector<mint>> dp(27,vector<mint>(s.size()+1,0));
    dp[0][0] = 1;
    rep(i,26){
        rep(j,s.size()+1){
            for(ll k=0;k<=num[i];k++){
                if(j+k > s.size())break;
                dp[i+1][j+k] += dp[i][j]/kaizyo[k];
            }
        }
    }
    mint ans = 0;
    for(ll i=1;i<=s.size();i++){
        ans += dp[26][i]*kaizyo[i];
    }
    print(ans.val());
    
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc234/submissions/39307874
 * Submitted at: 2023-02-28 15:39:45
 * Problem URL: https://atcoder.jp/contests/abc234/tasks/abc234_f
 * Result: AC
 * Execution Time: 41 ms
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
    ll size = s.size();
    rep(i,size)num[s[i]-'a']++;
    vector<mint> kaizyo(size+1,1),r_kaizyo(size+1,1);
    for(int i=1;i<=size;i++){
        kaizyo[i] = kaizyo[i-1]*i;
        r_kaizyo[i] = mint(1)/kaizyo[i];
    }

    vector<vector<mint>> dp(27,vector<mint>(size+1,0));
    dp[0][0] = 1;
    rep(i,26){
        for(ll j=0;j<=size;j++){
            if(dp[i][j] == 0)continue;
            for(ll k=0;k<=num[i];k++){
                dp[i+1][j+k] += dp[i][j]*r_kaizyo[k];
            }
        }
    }
    mint ans = 0;
    for(ll i=1;i<=size;i++){
        ans += dp[26][i]*kaizyo[i];
    }
    print(ans.val());
    
    return 0;
}
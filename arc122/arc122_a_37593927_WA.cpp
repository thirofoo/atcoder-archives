/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc122/submissions/37593927
 * Submitted at: 2022-12-28 15:24:36
 * Problem URL: https://atcoder.jp/contests/arc122/tasks/arc122_a
 * Result: WA
 * Execution Time: 30 ms
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
#define rep(i, n) for(ll i = 0; i < n; i++)

ll mod = 1000000007;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    vector<ll> a(n);
    rep(i,n)input(a[i]);
    vector dp(n,vector<P>(2,P(0,0)));
    dp[0][0] = P(a[0],1);
    rep(i,n-1){
        rep(j,2){
            auto [total,cnt] = dp[i][j];
            // cout << total << " ";

            if(cnt == 0)continue;
            if(j == 0){
                dp[i+1][0].first += total + cnt*a[i+1];
                dp[i+1][0].first %= mod;
                dp[i+1][0].second += cnt;
                dp[i+1][1].first += ((total - cnt*a[i+1])%mod + mod)%mod;
                dp[i+1][1].first %= mod;
                dp[i+1][1].second += cnt;
            }
            else{
                dp[i+1][0].first += total + cnt*a[i+1];
                dp[i+1][0].first %= mod;
                dp[i+1][0].second += cnt;
            }
        }
        // print();
    }
    print((dp[n-1][0].first + dp[n-1][1].first)%mod);
    
    return 0;
}
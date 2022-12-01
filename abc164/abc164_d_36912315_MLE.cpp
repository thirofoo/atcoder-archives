/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc164/submissions/36912315
 * Submitted at: 2022-12-01 19:24:17
 * Problem URL: https://atcoder.jp/contests/abc164/tasks/abc164_d
 * Result: MLE
 * Execution Time: 1871 ms
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
#define rep(i, n) for(int i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string s; input(s);
    vector<vector<int>> dp(s.size(),vector<int>(2019,0));
    rep(i,s.size())dp[i][s[i]-'0'] = 1;
    int ans = 0;
    rep(i,s.size()){
        rep(j,2019){
            if(j == 0)ans += dp[i][j];
            if(i+1 < s.size()){
                dp[i+1][(j*10 + (s[i+1]-'0'))%2019] += dp[i][j];
            }
        }
    }
    print(ans);
    
    return 0;
}
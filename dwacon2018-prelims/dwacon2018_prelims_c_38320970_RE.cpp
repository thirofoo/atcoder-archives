/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dwacon2018-prelims/submissions/38320970
 * Submitted at: 2023-01-25 21:47:34
 * Problem URL: https://atcoder.jp/contests/dwacon2018-prelims/tasks/dwacon2018_prelims_c
 * Result: RE
 * Execution Time: 107 ms
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
typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m; input(n,m);
    vector<ll> a(n),b(m);
    rep(i,n)input(a[i]);
    rep(i,m)input(b[i]);

    // a,bの各数字の個数
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vector<ll> c1,c2;
    ll cnt = 0,now = a[0];
    ll a_death = 0,b_death = 0;
    rep(i,n){
        b_death += a[i];
        if(now != a[i]){
            c1.push_back(cnt);
            now = a[i];
            cnt = 0;
        }
        cnt++;
    }
    c1.push_back(cnt);
    cnt = 0,now = b[0];
    rep(i,m){
        a_death += b[i];
        if(now != b[i]){
            c2.push_back(cnt);
            now = b[i];
            cnt = 0;
        }
        cnt++;
    }
    c2.push_back(cnt);

    // 前計算で分割数を求める
    // dp[i][j] : j の i 分割数 
    ll size = max(a_death,b_death);
    vector<vector<mint>> dp_div(size+1,vector<mint>(size+1,0));
    rep(i,size+1)dp_div[1][i] = 1;
    for(ll i=2;i<=size;i++){
        rep(j,size+1){
            dp_div[i][j] = dp_div[i-1][j] + (j-i >= 0 ? dp_div[i][j-i] : 0);
        }
    }

    // dp[i][j] : i種類の数字まで見て j kill した時の death の場合の数
    vector<vector<mint>> dp_a(c1.size()+1,vector<mint>(a_death+1,0));
    dp_a[0][0] = 1;
    rep(i,c1.size()){
        rep(j,a_death+1){
            // i種類目で 何kill したか
            for(ll k=0;k+j<=a_death;k++){
                dp_a[i+1][j+k] += dp_a[i][j]*dp_div[c1[i]][k];
            }
        }
    }
    vector<vector<mint>> dp_b(c2.size()+1,vector<mint>(b_death+1,0));
    dp_b[0][0] = 1;
    rep(i,c2.size()){
        rep(j,b_death+1){
            // i種類目で 何kill したか
            for(ll k=0;k+j<=b_death;k++){
                dp_b[i+1][j+k] += dp_b[i][j]*dp_div[c2[i]][k];
            }
        }
    }

    print( (dp_a[c1.size()][a_death]*dp_b[c2.size()][b_death]).val() );
    
    return 0;
}
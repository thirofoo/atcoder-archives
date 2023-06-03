/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/41927174
 * Submitted at: 2023-06-03 16:19:09
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_bd
 * Result: AC
 * Execution Time: 82 ms
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
    
    ll n, s; input(n,s);
    vector<ll> a(n),b(n);
    rep(i,n){
        input(a[i]);
        input(b[i]);
    }
    // ただのdp復元
    vector<vector<ll>> dp(n+1,vector<ll>(s+1,-1));
    dp[0][0] = -2;
    rep(i,n){
        rep(j,s){
            if(dp[i][j] == -1)continue;
            if(j+a[i] <= s)dp[i+1][j+a[i]] = j;
            if(j+b[i] <= s)dp[i+1][j+b[i]] = j;
        }
    }
    if(dp[n][s] == -1){
        return print("Impossible"),0;
    }
    stack<char> st;
    ll x = n, y = s;
    while(x != 0){
        if(y-dp[x][y] == a[x-1]) st.push('A');
        else st.push('B');
        y = dp[x][y];
        x--;
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    print();

    return 0;
}
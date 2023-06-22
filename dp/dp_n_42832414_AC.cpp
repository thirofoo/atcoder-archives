/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/42832414
 * Submitted at: 2023-06-23 00:00:02
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_n
 * Result: AC
 * Execution Time: 88 ms
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

vector<ll> a;
vector<vector<ll>> dp;

ll f(ll left, ll right){
    // 解説AC memo化再起
    // 問題を逆から捉える → 1体のスライムを分解する問題
    // → 分解する場所を全探索して再起
    // 分割のmemoの状態数 O(N^2), 1状態当たり O(N)
    // → O(N^3)
    if(dp[left][right] < 1e14)return dp[left][right];
    if(left+1 == right){
        dp[left][right] = a[right+1] - a[left];
        return dp[left][right];
    }
    ll cand = 1e14;
    for(ll i=left;i<right;i++){
        cand = min(cand,f(left,i) + f(i+1,right));
    }
    dp[left][right] = cand + a[right+1] - a[left];
    return dp[left][right];
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    dp.assign(n,vector<ll>(n,1e14));
    a.assign(n+1,0);
    rep(i,n){
        input(a[i+1]);
        a[i+1] += a[i];
        dp[i][i] = 0;
    }
    print( f(0,n-1) );
    
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/code-festival-2015-morning-middle/submissions/38941058
 * Submitted at: 2023-02-17 17:16:07
 * Problem URL: https://atcoder.jp/contests/code-festival-2015-morning-middle/tasks/cf_2015_morning_hard_a
 * Result: AC
 * Execution Time: 21 ms
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
    vector<ll> a(n);
    rep(i,n)input(a[i]);

    // n偶数：黒染め 奇数：白染め
    // 累積和作って差分更新
    vector<ll> rui(n+1,0),add(n+1,0);
    rep(i,n){
        rui[i+1] = rui[i]+a[i];
        add[i+1] = add[i]+i+1;
    }
    ll left = 0,right = 0,ans = LLONG_MAX;
    for(int i=1;i<n;i++)right += a[i]*i;
    if(n%2)ans = min(ans,right+left+add[n-1-1]);
    
    // 1-idxに注意
    for(int i=2;i<=n;i++){
        ll cand = 0;
        left += rui[i-1] - rui[0];
        right -= rui[n] - rui[i-1];
        cand += right + left;
        cand += add[i-1-1] + (n-i-1 >= 0 ? add[n-i-1] : 0);
        if(i%2 == n%2)ans = min(ans,cand);
    }
    print(ans);
    
    return 0;
}
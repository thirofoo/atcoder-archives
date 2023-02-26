/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc291/submissions/39257357
 * Submitted at: 2023-02-26 22:02:45
 * Problem URL: https://atcoder.jp/contests/abc291/tasks/abc291_f
 * Result: WA
 * Execution Time: 75 ms
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
    
    ll n,m; input(n,m);
    vector<string> s(n);
    rep(i,n)input(s[i]);
    vector<ll> dp1(n,LLONG_MAX),dp2(n,LLONG_MAX);
    dp1[0] = 0;
    dp2[n-1] = 0;
    for(ll i=1;i<n;i++){
        for(ll j=i-1;j>=0;j--){
            if(i-j-1 >= m)break;
            if(s[j][i-j-1] == '1')dp1[i] = min(dp1[i],dp1[j]+1);
        }
    }
    for(ll i=n-1;i>=0;i--){
        for(ll j=i-1;j>=0;j--){
            if(i-j-1 >= m)break;
            if(s[j][i-j-1] == '1')dp2[j] = min(dp2[j],dp2[i]+1);
        }
    }
    for(ll i=1;i<=n-2;i++){
        ll ans = LLONG_MAX;
        for(ll left = max(i-m+1,0LL);left<i;left++){
            for(ll right = i+1;right<min(i+m,n);right++){
                if(right-left > m)continue;
                if(s[left][right-left-1] == '1'){
                    if(dp1[left] != LLONG_MAX && dp2[right] != LLONG_MAX){
                        ans = min(ans,dp1[left]+dp2[right]+1);
                    }
                }
            }
        }
        cout << (ans == LLONG_MAX ? -1 : ans) << " ";
    }
    print();
    
    return 0;
}
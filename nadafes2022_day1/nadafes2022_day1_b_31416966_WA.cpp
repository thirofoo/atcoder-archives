/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/nadafes2022_day1/submissions/31416966
 * Submitted at: 2022-05-03 19:32:49
 * Problem URL: https://atcoder.jp/contests/nadafes2022_day1/tasks/nadafes2022_day1_b
 * Result: WA
 * Execution Time: 11 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

ll mod = 998244353;

ll Conbination(ll n,ll k){
    if(k < 0)return 0;
    if(k == 0)return 1;
    if(k > n-k)k = n-k;
    ll ans = 1;
    rep(i,k){
        ans *= n-k+(i+1);
        ans /= i+1;
        ans %= mod;
    }
    return ans;
}

int main() {
    ll n,k; cin >> n >> k;
    cout << Conbination(n-(n+1)/2,k-(n+1)/2) << endl; 
    return 0;
}
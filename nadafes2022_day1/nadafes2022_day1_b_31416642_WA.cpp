/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/nadafes2022_day1/submissions/31416642
 * Submitted at: 2022-05-03 19:11:54
 * Problem URL: https://atcoder.jp/contests/nadafes2022_day1/tasks/nadafes2022_day1_b
 * Result: WA
 * Execution Time: 6 ms
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

int mod = 998244353;

ll Conbination(ll n,ll k){
    if(k < 0)return 0;
    else if(k == 0)return 1;
    else if(k > n-k)return Conbination(n,n-k);
    ll ans = 1;
    rep(i,k){
        ans *= n-i;
        ans /= i+1;
        ans %= mod;
    }
    return ans;
}

int main() {
    int n,k; cin >> n >> k;
    cout << Conbination(n-(n+1)/2,k-(n+1)/2) << endl; 
    return 0;
}
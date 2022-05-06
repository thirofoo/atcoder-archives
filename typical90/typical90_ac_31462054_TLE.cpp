/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/31462054
 * Submitted at: 2022-05-06 11:13:03
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_ac
 * Result: TLE
 * Execution Time: 4410 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int w,n; cin >> w >> n;
    vector<int> height(w,0);
    rep(i,n){
        int l,r; cin >> l >> r;
        l--; r--;
        int tmp = 0;
        for(int j=l;j<=r;j++)tmp = max(tmp,height[j]);
        for(int j=l;j<=r;j++)height[j] = tmp+1;
        cout << tmp+1 << endl;
    }
    return 0;
}
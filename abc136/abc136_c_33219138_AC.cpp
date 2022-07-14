/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc136/submissions/33219138
 * Submitted at: 2022-07-14 18:37:22
 * Problem URL: https://atcoder.jp/contests/abc136/tasks/abc136_c
 * Result: AC
 * Execution Time: 22 ms
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
    
    int n; cin >> n;
    vector<int> height(n);
    rep(i,n)cin >> height[i];
    rep(i,n-1){
        if(height[i+1] > height[i])height[i+1]--;
    }
    int now = height[0];
    rep(i,n-1){
        if(height[i+1] < height[i]){
            return cout << "No" << endl,0;
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}
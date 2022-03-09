/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc197/submissions/29969284
 * Submitted at: 2022-03-09 17:12:32
 * Problem URL: https://atcoder.jp/contests/abc197/tasks/abc197_c
 * Result: WA
 * Execution Time: 8 ms
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

int main() {
    int n; cin >> n;
    vector<int> a(n),a1(n-1),a2(n-1);
    rep(i,n)cin >> a[i];
    rep(i,n-1){
        if(i == 0)a1[i] = a[i];
        else a1[i] = a[i] | a1[i-1];
    }
    reverse(a.begin(),a.end());
    rep(i,n-1){
        if(i == 0)a2[i] = a[i];
        else a2[i] = a[i] | a2[i-1];
    }
    reverse(a2.begin(),a2.end());

    int ans = INT_MAX;
    for(int i=0;i<n-1;i++){
        ans = min(ans,a1[i]^a2[i]);
    }
    cout << ans << endl;
    return 0;
}
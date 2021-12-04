/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc210/submissions/27688457
 * Submitted at: 2021-12-04 18:30:21
 * Problem URL: https://atcoder.jp/contests/abc210/tasks/abc210_c
 * Result: TLE
 * Execution Time: 2206 ms
 */

#include <bits/stdc++.h>
#include <cmath> //abs関数で絶対値を使える。
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < n; ++i)

int main(){
    int n,k,ans=0;
    // int ans=0;
    cin >> n >> k;
    vector<int> color(n);
    rep(i,n)cin >> color[i];
    rep(i,n-k+1){
        set<int> colors;
        rep(j,k) colors.insert(color[i+j]);
        int size = colors.size();
        ans = max(ans,size);
    }
    cout << ans << endl;
    return 0;
}
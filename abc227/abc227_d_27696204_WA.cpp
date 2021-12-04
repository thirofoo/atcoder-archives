/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc227/submissions/27696204
 * Submitted at: 2021-12-04 23:36:38
 * Problem URL: https://atcoder.jp/contests/abc227/tasks/abc227_d
 * Result: WA
 * Execution Time: 2205 ms
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
    int n,k;
    int ans = 0;
    cin >> n >> k;
    vector<int> pro(n);
    rep(i,n)cin >> pro[i];
    sort(pro.begin(),pro.end(),[](int a,int b){
        return a < b;
    });
    while(pro[n-k] != 0){
        rep(i,k){
            pro[n-i-1]--;
        }
        ans++;
        sort(pro.begin(),pro.end(),[](int a,int b){
            return a < b;
        });
    }
    cout << ans << endl;
    return 0;
}
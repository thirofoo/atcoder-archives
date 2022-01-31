/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc227/submissions/28979746
 * Submitted at: 2022-02-01 00:00:13
 * Problem URL: https://atcoder.jp/contests/abc227/tasks/abc227_d
 * Result: WA
 * Execution Time: 87 ms
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
    int n,k; cin >> n >> k;
    vector<ll> num(n);
    rep(i,n)cin >> num[i];
    ll ok = 0,ng = 1e18;
    while(ng-ok>1){
        ll mid = (ng+ok)/2,sum = 0;
        for(auto a:num)sum += (mid > a ? a : mid);
        // cout << ok << " " << mid << " " << ng << " " << sum << endl;
        if(mid*k <= sum)ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc232/submissions/28016567
 * Submitted at: 2021-12-19 22:34:36
 * Problem URL: https://atcoder.jp/contests/abc232/tasks/abc232_c
 * Result: RE
 * Execution Time: 126 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
  #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> ans1(n,0);
    vector<int> ans2(n,0);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        ans1[a]++;
        ans1[b]++;
    }
    rep(i,m){
        int a,b;
        cin >> a >> b;
        ans2[a]++;
        ans2[b]++;
    }
    sort(ans1.begin(),ans1.end());
    sort(ans2.begin(),ans2.end());
    rep(i,m)if(ans1[i] != ans2[i])return cout << "No" << endl,0;
    cout << "Yes" << endl;
    return 0;
}
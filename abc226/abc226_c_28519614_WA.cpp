/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc226/submissions/28519614
 * Submitted at: 2022-01-15 15:51:20
 * Problem URL: https://atcoder.jp/contests/abc226/tasks/abc226_c
 * Result: WA
 * Execution Time: 2206 ms
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

ll ans = 0;

void solve(vector<int> &times,vector<vector<int>> &x,int n){
    for(int i:x[n]){
        solve(times,x,i);
        ans += times[i];
    }
}

int main() {
    int n; cin >> n;
    vector<int> times(n+1);
    vector<vector<int>> x(n+1);
    for(int i=1;i<=n;i++){
        int k;
        cin >> times[i] >> k;
        for(int j=0;j<k;j++){
            int a; cin >> a;
            x[i].push_back(a);
        }
    }
    solve(times,x,n);
    cout << ans+times[n] << endl;
    return 0;
}
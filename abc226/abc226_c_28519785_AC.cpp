/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc226/submissions/28519785
 * Submitted at: 2022-01-15 16:00:37
 * Problem URL: https://atcoder.jp/contests/abc226/tasks/abc226_c
 * Result: AC
 * Execution Time: 149 ms
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

void solve(vector<int> &times,vector<int> &learned,vector<vector<int>> &x,int n){
    for(int i:x[n]){
        if(learned[i])continue;
        solve(times,learned,x,i);
        learned[i] = 1;
        ans += times[i];
    }
}

int main() {
    int n; cin >> n;
    vector<int> times(n+1),learned(n+1);
    vector<vector<int>> x(n+1);
    for(int i=1;i<=n;i++){
        int k;
        cin >> times[i] >> k;
        for(int j=0;j<k;j++){
            int a; cin >> a;
            x[i].push_back(a);
        }
    }
    solve(times,learned,x,n);
    cout << ans+times[n] << endl;
    return 0;
}
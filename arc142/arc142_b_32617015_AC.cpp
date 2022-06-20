/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc142/submissions/32617015
 * Submitted at: 2022-06-20 12:26:39
 * Problem URL: https://atcoder.jp/contests/arc142/tasks/arc142_b
 * Result: AC
 * Execution Time: 31 ms
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
    
    int n,cnt = 0; cin >> n;
    vector<vector<int>> ans(n,vector<int>(n,0));
    bool f1 = false,f2 = false;
    rep(i,n)rep(j,n){
        if((i+j)%2 == 0){
            ans[i][j] = 1+cnt;
            f1 = true;
        }
        else{
            ans[i][j] = n*n-cnt;
            f2 = true;
        }
        if(f1 && f2){
            cnt++;
            f1 = false;
            f2 = false;
        }
    }
    rep(i,n){
        rep(j,n){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
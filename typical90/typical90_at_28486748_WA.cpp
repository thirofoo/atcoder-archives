/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28486748
 * Submitted at: 2022-01-13 11:28:05
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_at
 * Result: WA
 * Execution Time: 97 ms
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
    ll n,count = 0; cin >> n;
    vector<vector<int>> seq(3,vector<int>(46,0));
    rep(i,3){
        rep(j,n){
            int a; cin >> a;
            seq[i][a%46]++;
        }
    }
    rep(i,3){
        rep(j,46){
            cout << seq[i][j] << " ";
        }
        cout << endl;
    }
    rep(i,46)rep(j,46)rep(k,46){
        if((i+j+k)%46 != 0)continue;
        count += seq[0][i]*seq[1][j]*seq[2][k];
    }
    cout << count << endl;
    return 0;
}
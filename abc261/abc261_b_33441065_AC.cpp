/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc261/submissions/33441065
 * Submitted at: 2022-07-23 21:11:01
 * Problem URL: https://atcoder.jp/contests/abc261/tasks/abc261_b
 * Result: AC
 * Execution Time: 20 ms
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
    
    ll n; cin >> n;
    vector<string> a(n);
    rep(i,n)cin >> a[i];

    rep(i,n){
        for(int j=i+1;j<n;j++){
            if(a[i][j] == 'W'){
                if(a[j][i] != 'L'){
                    return cout << "incorrect" << endl,0;
                }
            }
            else if(a[i][j] == 'L'){
                if(a[j][i] != 'W'){
                    return cout << "incorrect" << endl,0;
                }
            }
            if(a[i][j] == 'D'){
                if(a[j][i] != 'D'){
                    return cout << "incorrect" << endl,0;
                }
            }
        }
    }
    cout << "correct" << endl;
    
    return 0;
}
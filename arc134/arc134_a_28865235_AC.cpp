/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc134/submissions/28865235
 * Submitted at: 2022-01-29 21:36:31
 * Problem URL: https://atcoder.jp/contests/arc134/tasks/arc134_a
 * Result: AC
 * Execution Time: 54 ms
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
    ll n,l,w,left = 0,ans = 0; cin >> n >> l >> w;
    vector<ll> sheet(n);
    for(int i=0;i<n;i++)cin >> sheet[i];
    if(sheet[0] != 0){
        if(sheet[0]%w == 0)ans += sheet[0]/w;
        else ans += sheet[0]/w+1;
    }
    if(sheet[n-1]+w < l){
        if((l-sheet[n-1]-w)%w == 0)ans += (l-sheet[n-1]-w)/w;
        else ans += (l-sheet[n-1]-w)/w+1;
    }
    for(int i=0;i<n-1;i++){
        if(sheet[i+1]-sheet[i] <= w)continue;
        if((sheet[i+1]-sheet[i]-w)%w == 0)ans += (sheet[i+1]-sheet[i]-w)/w;
        else ans += (sheet[i+1]-sheet[i]-w)/w+1;
    }
    cout << ans << endl;
    return 0;
}
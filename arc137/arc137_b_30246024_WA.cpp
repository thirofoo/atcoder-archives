/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc137/submissions/30246024
 * Submitted at: 2022-03-19 22:55:47
 * Problem URL: https://atcoder.jp/contests/arc137/tasks/arc137_b
 * Result: WA
 * Execution Time: 45 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    int tmp1 = 0,tmp2 = 0,ans = 0;
    rep(i,n){
        if(i != 0 && a[i-1] == 1 && a[i] == 0){
            ans = max(ans,tmp1+1);
            tmp1 = 0;
        }
        else tmp1++;
    }
    rep(i,n){
        if(i != 0 && a[i-1] == 0 && a[i] == 1){
            ans = max(ans,tmp2+1);
            tmp2 = 0;
        }
        else tmp2++;
    }
    if(tmp1)ans = max(ans,tmp1+1);
    if(tmp2)ans = max(ans,tmp2+1);
    cout << ans << endl;
    return 0;
}
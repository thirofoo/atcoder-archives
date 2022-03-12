/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc194/submissions/30020114
 * Submitted at: 2022-03-12 16:22:50
 * Problem URL: https://atcoder.jp/contests/abc194/tasks/abc194_e
 * Result: RE
 * Execution Time: 320 ms
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
    int n,m; cin >> n >> m;
    vector<int> a(n),used(n,0);
    rep(i,n)cin >> a[i];
    rep(i,m)used[a[i]]++;

    int ans = n;
    rep(i,n){
        if(used[i] == 0){
            ans = i;
            break;
        }
    }
    for(int i=m;i<n;i++){
        used[a[i-m]]--;
        used[a[i]]++;
        if(used[a[m-i]] == 0)ans = min(ans,a[m-i]);
    }
    cout << ans << endl;
    return 0;
}
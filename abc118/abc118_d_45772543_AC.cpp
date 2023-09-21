/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc118/submissions/45772543
 * Submitted at: 2023-09-21 19:10:35
 * Problem URL: https://atcoder.jp/contests/abc118/tasks/abc118_d
 * Result: AC
 * Execution Time: 2 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

vector<ll> num = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説AC
    // 敗因 : dpはしたが、「小さい方から確定させていく」ことに気付けず使うべき数字の順番で遷移をした (普通に誤り)
    ll n, m; cin >> n >> m;
    vector<ll> a(m);
    rep(i,m) cin >> a[i];
    sort( a.begin(), a.end(), [](ll e1, ll e2){
        return e1 > e2;
    });
    // dp[i] : 使用マッチ本数i本の時の最大桁数
    // ↑ で dp復元
    vector<ll> dp(n+1,-1), use(n+1,0);
    dp[0] = 0;
    rep(i,n+1) {
        rep(j,m) {
            if( i-num[a[j]] < 0 || dp[i-num[a[j]]] == -1 || dp[i] >= dp[i-num[a[j]]] + 1 ) continue;
            dp[i] = dp[i-num[a[j]]] + 1;
            use[i] = a[j];
        }
    }
    string ans = "";
    ll now = n;

    while( dp[now] ) {
        ans += '0' + use[now];
        now -= num[use[now]];
    }
    cout << ans << endl;
    
    return 0;
}
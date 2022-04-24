/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc139/submissions/31249022
 * Submitted at: 2022-04-24 23:37:03
 * Problem URL: https://atcoder.jp/contests/arc139/tasks/arc139_a
 * Result: WA
 * Execution Time: 2205 ms
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
    ll n; cin >> n;
    vector<ll> t(n),s(n);
    rep(i,n)cin >> t[i];
    rep(i,n){
        s[i] = (1LL << t[i]);
    }
    ll cnt,ans = s[0];
    rep(i,n-1){
        cout << ans << endl;
        if(t[i+1] < t[i])ans = (ans | s[i+1]);
        else{
            cnt = t[i+1];
            while((s[i+1] | (1LL << cnt)) <= ans)cnt++;
            ans = s[i+1] | (1LL << cnt);
        }
    }
    cout << ans << endl;
    return 0;
}
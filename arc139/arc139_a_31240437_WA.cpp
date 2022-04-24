/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc139/submissions/31240437
 * Submitted at: 2022-04-24 21:47:11
 * Problem URL: https://atcoder.jp/contests/arc139/tasks/arc139_a
 * Result: WA
 * Execution Time: 26 ms
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
    ll cnt = t[0],ans = s[0];
    rep(i,n-1){
        if(t[i+1] >= t[i]){
            if(s[i+1] > ans)ans = s[i+1];
            else{
                cnt++;
                ans = s[i+1] | (1LL << cnt);
            }
        }
        else ans |= s[i+1];
    }
    cout << ans << endl;
    return 0;
}
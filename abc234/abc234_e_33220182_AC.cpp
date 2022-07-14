/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc234/submissions/33220182
 * Submitted at: 2022-07-14 19:47:23
 * Problem URL: https://atcoder.jp/contests/abc234/tasks/abc234_e
 * Result: AC
 * Execution Time: 6 ms
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
    
    string x; cin >> x;
    ll size = x.size(),ans = LLONG_MAX;
    for(char l='1';l<='9';l++){
        for(ll i=-9;i<=9;i++){
            string tmp = "";
            ll d = 0;
            rep(j,size){
                if('0' <= l+d && l+d <= '9'){
                    tmp += l+d;
                    d += i;
                }
                else break;
            }
            if(tmp.size() == size && stoll(tmp) >= stoll(x))ans = min(stoll(tmp),ans);
        }
    }
    cout << ans << endl;
    return 0;
}
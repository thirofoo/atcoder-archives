/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc251/submissions/31691570
 * Submitted at: 2022-05-14 22:40:03
 * Problem URL: https://atcoder.jp/contests/abc251/tasks/abc251_d
 * Result: TLE
 * Execution Time: 2220 ms
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
    
    int w; cin >> w;
    set<int> ans;

    ll tmp = 1;
    while(tmp <= w){
        ans.insert(tmp);
        tmp <<= 1;
        tmp += 1;
    }
    
    while(ans.size() <= 300){
        for(auto k:ans){
            for(auto l:ans){
                for(auto m:ans){
                    if(k == l || l == m || m == k)continue;
                    ans.insert(k+l+m);
                }
            }
        }
    }

    cout << ans.size() << endl;
    for(auto k:ans)cout << k << " ";
    cout << endl;
    
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc251/submissions/31696895
 * Submitted at: 2022-05-15 00:01:50
 * Problem URL: https://atcoder.jp/contests/abc251/tasks/abc251_d
 * Result: WA
 * Execution Time: 7 ms
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
    vector<int> a,ans;
    for(int i=1;i<100;i++)a.push_back(i);
    rep(i,100){
        rep(j,3){
            ans.push_back(a[i]*pow(10,j));
        }
    }
    cout << ans.size() << endl;
    for(auto k:ans)cout << k << " ";
    cout << endl;
    return 0;
}
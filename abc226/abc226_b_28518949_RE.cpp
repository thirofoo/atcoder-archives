/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc226/submissions/28518949
 * Submitted at: 2022-01-15 15:16:16
 * Problem URL: https://atcoder.jp/contests/abc226/tasks/abc226_b
 * Result: RE
 * Execution Time: 2206 ms
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
    int n,ans = 0; cin >> n;
    vector<vector<int>> size(n+1),sequence(n+1);
    rep(i,n){
        int l; cin >> l;
        rep(j,l){
            int a; cin >> a;
            sequence[i+1].push_back(a);
        }
        bool frag = true;
        for(auto k:size[l]){
            if(sequence[i+1] == sequence[k]){
                frag = false;
                break;
            }
        }
        if(frag)ans++;
        size[l].push_back(i+1);
    }
    cout << ans << endl;
    return 0;
}
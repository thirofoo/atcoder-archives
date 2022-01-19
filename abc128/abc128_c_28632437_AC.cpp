/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc128/submissions/28632437
 * Submitted at: 2022-01-19 17:53:36
 * Problem URL: https://atcoder.jp/contests/abc128/tasks/abc128_c
 * Result: AC
 * Execution Time: 9 ms
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
    bool frag = true;
    int n,m,ans = 0; cin >> n >> m;
    vector<vector<int>> button(m,vector<int>(n,0));
    vector<int> light(m);
    rep(i,m){
        int k; cin >> k;
        rep(j,k){
            int a; cin >> a;
            button[i][a-1]++;
        }
    }

    rep(i,m) cin >> light[i];
    for(int i=0;i<(1LL << n);i++){
        vector<int> bright(m,0);
        rep(j,m){
            rep(k,n){
                if(i&(1 << k) && button[j][k]){bright[j]++; bright[j] %= 2;}
            }
        }
        rep(j,m){
            if(light[j] != bright[j]){
                frag = false;
                break;
            }
        }
        if(frag)ans++;
        frag = true;
    }
    cout << ans << endl;
    return 0;
}
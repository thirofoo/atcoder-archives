/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc197/submissions/29969849
 * Submitted at: 2022-03-09 17:46:37
 * Problem URL: https://atcoder.jp/contests/abc197/tasks/abc197_c
 * Result: AC
 * Execution Time: 48 ms
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
    
    int ans = INT_MAX;

    rep(i,(1 << (n-1))){
        int OR = a[0],XOR = 0;
        rep(j,n-1){
            if(i & (1 << j)){
                XOR ^= OR;
                OR = 0;
            }
            OR |= a[j+1];
        }
        XOR ^= OR;
        ans = min(ans,XOR);
    }
    cout << ans << endl;
    return 0;
}
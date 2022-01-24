/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28781565
 * Submitted at: 2022-01-24 23:57:33
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_ap
 * Result: AC
 * Execution Time: 13 ms
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

int mod = 1000000007;

int main() {
    int k; cin >> k;
    if(k%9 != 0)return cout << 0 << endl,0;
    vector<int> ok(k+1,0);
    ok[0] = 1;
    for(int i=1;i<k+1;i++){
        int tmp = min((int)i,9);
        for(int j=i-tmp;j<i;j++){
            ok[i] += ok[j]; ok[i] %= mod;
        }
    }
    cout << ok[k] << endl;
    return 0;
}
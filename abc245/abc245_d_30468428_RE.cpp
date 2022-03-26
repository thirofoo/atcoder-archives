/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc245/submissions/30468428
 * Submitted at: 2022-03-26 22:07:18
 * Problem URL: https://atcoder.jp/contests/abc245/tasks/abc245_d
 * Result: RE
 * Execution Time: 110 ms
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
    int n,m; cin >> n >> m;
    vector<int> a(n+1),c(n+m+1);
    rep(i,n+1)cin >> a[i];
    rep(i,n+m+1)cin >> c[i];

    vector<int> b;
    b.push_back(c[0]/a[0]);

    for(int i=1;i<m+1;i++){
        int tmp = c[i];
        rep(j,i){
            tmp -= a[i-j]*b[j];
        }
        tmp /= a[0];
        b.push_back(tmp);
    }

    rep(i,b.size())cout << b[i] << " ";
    cout << endl;

    return 0;
}
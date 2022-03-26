/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc245/submissions/30483142
 * Submitted at: 2022-03-26 22:56:06
 * Problem URL: https://atcoder.jp/contests/abc245/tasks/abc245_d
 * Result: WA
 * Execution Time: 4 ms
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
    vector<int> a(n+m+1,0),c(n+m+1,0);
    rep(i,n+1)cin >> a[i];
    rep(i,n+m+1)cin >> c[i];

    vector<int> b(n+m+1,0);
    int cnt = 0;
    rep(i,n+1){
        if(a[i] != 0)break;
        cnt++;
    }
    b[0] = c[cnt]/a[cnt];

    for(int i=1;i<m+1;i++){
        int tmp = c[i+cnt];
        rep(j,i-cnt){
            tmp -= a[i-j+cnt]*b[j+cnt];
        }
        tmp /= a[cnt];
        b[i] = tmp;
    }

    rep(i,m+1)cout << b[i] << " ";
    cout << endl;

    return 0;
}
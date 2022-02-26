/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc241/submissions/29665325
 * Submitted at: 2022-02-26 21:04:25
 * Problem URL: https://atcoder.jp/contests/abc241/tasks/abc241_b
 * Result: AC
 * Execution Time: 8 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,m; cin >> n >> m;
    map<int,int> a;
    rep(i,n){
        int x; cin >> x;
        a[x]++;
    }
    rep(i,m){
        int b; cin >> b;
        if(a[b] == 0)return cout << "No" << endl,0;
        a[b]--;
    }
    cout << "Yes" << endl;
    return 0;
}
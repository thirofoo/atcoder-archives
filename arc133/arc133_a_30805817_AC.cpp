/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc133/submissions/30805817
 * Submitted at: 2022-04-09 18:37:51
 * Problem URL: https://atcoder.jp/contests/arc133/tasks/arc133_a
 * Result: AC
 * Execution Time: 65 ms
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
    int n,ng = -1; cin >> n;
    vector<int> a(n);
    rep(i,n)cin >> a[i];

    rep(i,n-1){
        if(a[i+1] >= a[i])continue;
        ng = a[i]; break;
    }
    if(ng == -1)ng = a.back();
    rep(i,n)if(a[i] != ng)cout << a[i] << " ";
    cout << endl;
    return 0;
}
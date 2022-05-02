/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc154/submissions/31396521
 * Submitted at: 2022-05-02 17:13:04
 * Problem URL: https://atcoder.jp/contests/abc154/tasks/abc154_c
 * Result: AC
 * Execution Time: 183 ms
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
    map<int,int> b;
    rep(i,n){
        cin >> a[i];
        if(b[a[i]])return cout << "NO" << endl,0;
        b[a[i]]++;
    }
    cout << "YES" << endl;
    return 0;
}
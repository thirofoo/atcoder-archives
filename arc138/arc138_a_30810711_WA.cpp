/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc138/submissions/30810711
 * Submitted at: 2022-04-09 21:20:42
 * Problem URL: https://atcoder.jp/contests/arc138/tasks/arc138_a
 * Result: WA
 * Execution Time: 144 ms
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
    int n,k; cin >> n >> k;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    sort(a.begin()+k,a.end());
    ll ans = INT_MAX;
    rep(i,k){
        auto itr = upper_bound(a.begin()+k,a.end(),a[i]);
        if(itr == a.end())continue;
        ans = min(ans,(ll)(itr-a.begin()-i));
    }
    cout << (ans != INT_MAX ? ans : -1) << endl;
    return 0;
}
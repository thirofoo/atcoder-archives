/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/30319374
 * Submitted at: 2022-03-21 13:02:37
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_g
 * Result: AC
 * Execution Time: 665 ms
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
    sort(a.begin(),a.end());

    int q; cin >> q;
    rep(i,q){
        int b; cin >> b;
        auto itr = lower_bound(a.begin(),a.end(),b);
        if(itr == a.begin())cout << abs(*itr-b) << endl;
        else if(itr == a.end())cout << abs(*(itr-1)-b) << endl;
        else cout << min(abs(*itr-b),abs(*(itr-1)-b)) << endl;
    }
    return 0;
}
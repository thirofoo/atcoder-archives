/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28462410
 * Submitted at: 2022-01-11 16:39:23
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_g
 * Result: AC
 * Execution Time: 653 ms
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
    int n,q; cin >> n;
    vector<ll> classes(n);
    rep(i,n) cin >> classes[i]; 
    classes.push_back(1LL << 32);
    sort(classes.begin(),classes.end());
    cin >> q;
    vector<int> ans;
    rep(i,q){
        int a; cin >> a;
        auto itr = lower_bound(classes.begin(),classes.end(),a);
        if(*itr == classes[0]) ans.push_back(abs(classes[0]-a));
        else if(*itr == classes[n]) ans.push_back(abs(a-classes[n-1]));
        else ans.push_back(min(abs(*itr-a),abs(*(itr-1)-a)));
    }
    rep(i,q)cout << ans[i] << endl;
    return 0;
}
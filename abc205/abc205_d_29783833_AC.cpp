/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc205/submissions/29783833
 * Submitted at: 2022-03-01 12:38:32
 * Problem URL: https://atcoder.jp/contests/abc205/tasks/abc205_d
 * Result: AC
 * Execution Time: 262 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,q;cin >> n >> q;
    vector<P> a;
    for(int i=1;i<=n;i++){
        ll b; cin >> b;
        a.push_back(P(b-i,i));
    }
    rep(i,q){
        ll k; cin >> k;
        int itr = lower_bound(a.begin(),a.end(),P(k,0)) - a.begin();
        if(itr == n)cout << a[itr-1].first+a[itr-1].second+(k-a[itr-1].first) << endl;
        else cout << a[itr].first+a[itr].second-(a[itr].first+1-k) << endl;
    }
    return 0;
}
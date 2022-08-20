/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc146/submissions/34166487
 * Submitted at: 2022-08-20 21:13:16
 * Problem URL: https://atcoder.jp/contests/arc146/tasks/arc146_a
 * Result: AC
 * Execution Time: 79 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll,string> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<P> a;
    rep(i,n){
        string t; cin >> t;
        a.push_back(P(t.size(),t));
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());

    ll ans = 0;
    vector<int> p = {0,1,2};
    do{
        string tmp = a[p[0]].second+a[p[1]].second+a[p[2]].second;
        ans = max(ans,stoll(tmp));
    }while(next_permutation(p.begin(),p.end()));
    cout << ans << endl;
    
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc206/submissions/29839449
 * Submitted at: 2022-03-04 17:03:07
 * Problem URL: https://atcoder.jp/contests/abc206/tasks/abc206_c
 * Result: WA
 * Execution Time: 353 ms
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
    int n; cin >> n;
    vector<int> a(n);
    set<int> cnt;
    map<int,int> num;
    rep(i,n){
        cin >> a[i];
        num[a[i]]++;
    }
    ll ans = a.size()*(a.size()-1)/2;
    rep(i,n){
        if(!cnt.count(a[i])){
            ans -= num[a[i]]*(num[a[i]]-1)/2;
            cnt.insert(a[i]);
        }
    }
    cout << ans << '\n';
    return 0;
}
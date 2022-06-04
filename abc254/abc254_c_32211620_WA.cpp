/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc254/submissions/32211620
 * Submitted at: 2022-06-04 21:10:45
 * Problem URL: https://atcoder.jp/contests/abc254/tasks/abc254_c
 * Result: WA
 * Execution Time: 41 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n,k; cin >> n >> k;
    vector<int> a(n),b(n);
    rep(i,n)cin >> a[i];
    b = a;
    rep(i,n-k){
        if(a[i] > a[i+k])swap(a[i],a[i+k]);
    }
    sort(b.begin(),b.end());
    if(a == b)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
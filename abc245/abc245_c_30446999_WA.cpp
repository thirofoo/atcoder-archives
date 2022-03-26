/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc245/submissions/30446999
 * Submitted at: 2022-03-26 21:19:56
 * Problem URL: https://atcoder.jp/contests/abc245/tasks/abc245_c
 * Result: WA
 * Execution Time: 116 ms
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
    ll n,k; cin >> n >> k;
    vector<int> a(n),b(n);
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];

    ll s = a[0];
    for(int i=1;i<n;i++){
        bool frag = false;
        if(a[i-1]-k <= a[i] && a[i] <= a[i-1]+k)frag = true;
        if(b[i-1]-k <= a[i] && a[i] <= b[i-1]+k)frag = true;
        if(a[i-1]-k <= b[i] && b[i] <= a[i-1]+k)frag = true;
        if(b[i-1]-k <= b[i] && b[i] <= b[i-1]+k)frag = true;
        if(!frag)return cout << "No" << endl,0;
    }
    cout << "Yes" << endl;

    return 0;
}
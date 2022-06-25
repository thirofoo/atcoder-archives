/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc257/submissions/32713138
 * Submitted at: 2022-06-25 21:06:54
 * Problem URL: https://atcoder.jp/contests/abc257/tasks/abc257_b
 * Result: AC
 * Execution Time: 5 ms
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
    
    int n,k,q; cin >> n >> k >> q;
    vector<int> a(k,0);
    rep(i,k)cin >> a[i];
    while(q--){
        int l; cin >> l;
        l--;
        if(a[l] == n || count(a.begin(),a.end(),a[l]+1))continue;
        a[l]++;
    }
    for(auto l:a)cout << l << " ";
    cout << endl;

    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc172/submissions/28715964
 * Submitted at: 2022-01-23 19:46:01
 * Problem URL: https://atcoder.jp/contests/abc172/tasks/abc172_c
 * Result: WA
 * Execution Time: 123 ms
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
    int n,m,k,ans = 0; cin >> n >> m >> k;
    ll time = 0;
    queue<int> a,b;
    rep(i,n){
        int x; cin >> x;
        a.push(x);
    }
    rep(i,m){
        int x; cin >> x;
        b.push(x);
    }
    while(!(a.empty() && b.empty()) && time <= k){
        int A = a.empty() ? 1e10 : a.front();
        int B = b.empty() ? 1e10 : b.front();
        if(A < B) {a.pop(); time += A;}
        else {b.pop(); time += B;}
        ans++;
    }
    if(a.empty() && b.empty())cout << ans << endl;
    else cout << ans-1 << endl;
    return 0;
}
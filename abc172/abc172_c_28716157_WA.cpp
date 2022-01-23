/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc172/submissions/28716157
 * Submitted at: 2022-01-23 19:58:38
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
    while(!(a.empty() && b.empty())){
        int A = a.empty() ? 1e10 : a.front();
        int B = b.empty() ? 1e10 : b.front();
        // cout << A << " " << B << " " << time + min(A,B) << " " << ans << endl;
        if(A < B && time + A <= k) {time += A; a.pop();}
        else if(B <= A && time + B <= k) {time += B; b.pop();}
        else break;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
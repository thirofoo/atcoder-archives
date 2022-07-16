/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc144/submissions/33259695
 * Submitted at: 2022-07-16 21:09:18
 * Problem URL: https://atcoder.jp/contests/arc144/tasks/arc144_a
 * Result: AC
 * Execution Time: 8 ms
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
    
    ll n,m = 0; cin >> n;
    queue<ll> ans;
    if(n%4 != 0){
        ans.push(n%4);
        m += (n%4)*2;
    }
    rep(i,n/4){
        ans.push(4);
        m += 8;
    }
    cout << m << endl;
    while(!ans.empty()){
        cout << ans.front();
        ans.pop();
    }
    cout << endl;
    
    return 0;
}
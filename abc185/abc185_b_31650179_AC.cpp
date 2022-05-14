/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc185/submissions/31650179
 * Submitted at: 2022-05-14 17:22:57
 * Problem URL: https://atcoder.jp/contests/abc185/tasks/abc185_b
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
    
    int n,m,t,a,b = 0; cin >> n >> m >> t;
    int now = n;
    while(m--){
        cin >> a;
        now -= a-b;
        if(now <= 0)return cout << "No" << endl,0;
        cin >> b;
        now = min(now+b-a,n);
    }
    cout << (now-(t-b) > 0  ? "Yes" : "No") << endl;
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc131/submissions/33393067
 * Submitted at: 2022-07-21 18:42:41
 * Problem URL: https://atcoder.jp/contests/abc131/tasks/abc131_b
 * Result: AC
 * Execution Time: 6 ms
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
    
    ll n,l,ans = 0; cin >> n >> l;
    for(int i=0;i<n;i++)ans += l+i;
    if(l <= 0 && 0 <= l+n-1){
        cout << ans << endl;
    }
    else{
        int tmp;
        if(abs(l+n-1) <= abs(l)){
            tmp = l+n-1;
        }
        else tmp = l;
        cout << ans - tmp << endl;
    }
    
    return 0;
}
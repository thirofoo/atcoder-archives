/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc124/submissions/34113547
 * Submitted at: 2022-08-18 00:18:40
 * Problem URL: https://atcoder.jp/contests/arc124/tasks/arc124_a
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
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll n,k; cin >> n >> k;
    mint ans = 1;
    vector<ll> l(n+2,0),r(n+2,0);
    vector<bool> card(n,false);
    rep(i,k){
        char c; int m; cin >> c >> m;
        if(c == 'R'){
            r[0]++;
            r[m]--;
            card[m-1] = true;
        }
        else{
            l[n+1]++;
            l[m]--;
            card[m-1] = true;
        }
    }

    rep(i,n+1)r[i+1] += r[i];
    for(int i=n+1;i>=1;i--)l[i-1] += l[i];
    rep(i,n)if(!card[i])ans *= (mint)(l[i+1]+r[i+1]);

    cout << ans.val() << endl;
    return 0;
}
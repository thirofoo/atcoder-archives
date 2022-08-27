/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc266/submissions/34405010
 * Submitted at: 2022-08-27 22:39:54
 * Problem URL: https://atcoder.jp/contests/abc266/tasks/abc266_e
 * Result: WA
 * Execution Time: 8 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<vector<vector<ld>>> p(6,vector<vector<ld>>(n+1,vector<ld>(6,0)));
    ld ans = 0;
    rep(i,6)p[i][0][0] = 1;
    rep(l,n){
        rep(m,6){
            rep(i,6){
                vector<ld> t(6,0);
                ld tmp = 0;
                rep(j,6){
                    if(j >= i){
                        tmp += p[m][l][j]*(j+1);
                        t[j] += p[m][l][j];
                    }
                    else{
                        rep(k,6){
                            tmp += p[m][l][j]*(k+1)/6;
                            t[k] += p[m][l][j]/6;
                        }
                    }
                }
                if(tmp > ans)p[m][l] = t;
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}
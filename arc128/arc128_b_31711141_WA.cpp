/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc128/submissions/31711141
 * Submitted at: 2022-05-15 17:37:58
 * Problem URL: https://atcoder.jp/contests/arc128/tasks/arc128_b
 * Result: WA
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
    
    int t; cin >> t;
    rep(i,t){
        int r,g,b; cin >> r >> g >> b;

        vector<int> tmp(3);
        tmp[0] = r; tmp[1] = g; tmp[2] = b;
        sort(tmp.begin(),tmp.end());
        r = tmp[0]; g = tmp[1]; b = tmp[2];

        if((r-g)%3 == 0){
            if(abs(r-g)/3 > b)cout << -1 << endl;
            else cout << max(r,g) << endl;
        }   
        else if((g-b)%3 == 0){
            if(abs(g-b)/3 > r)cout << -1 << endl;
            else cout << max(g,b) << endl;
        }
        else if((b-r)%3 == 0){
            if(abs(b-r)/3 > g)cout << -1 << endl;
            else cout << max(b,r) << endl;
        }
        else cout << -1 << endl;
    }   
    return 0;
}
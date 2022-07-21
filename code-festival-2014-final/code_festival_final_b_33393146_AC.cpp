/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/code-festival-2014-final/submissions/33393146
 * Submitted at: 2022-07-21 18:46:50
 * Problem URL: https://atcoder.jp/contests/code-festival-2014-final/tasks/code_festival_final_b
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
    
    int ans = 0;string s; cin >> s;
    int size = s.size();
    rep(i,size){
        if(i%2 == 0){
            ans += s[i]-'0';
        }
        else{
            ans -= s[i]-'0';
        }
    }
    cout << ans << endl;
    
    return 0;
}
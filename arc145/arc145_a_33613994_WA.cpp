/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc145/submissions/33613994
 * Submitted at: 2022-07-30 21:12:43
 * Problem URL: https://atcoder.jp/contests/arc145/tasks/arc145_a
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
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll n; string s; cin >> n >> s;
    if(s[0] == 'A' && s[n-1] == 'B')return cout << "No" << endl,0;
    if(n%2 == 1)return cout << "Yes" << endl,0;
    else{
        rep(i,n/2-1){
            if(s[i] == 'B' && s[n-1-i] == 'A'){
                s[i] = 'A';
                s[i+1] = 'B';
            }
        }
        if(s[n/2] == s[n/2+1])cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}
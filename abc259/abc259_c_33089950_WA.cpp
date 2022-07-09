/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc259/submissions/33089950
 * Submitted at: 2022-07-09 21:28:21
 * Problem URL: https://atcoder.jp/contests/abc259/tasks/abc259_c
 * Result: WA
 * Execution Time: 11 ms
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
    
    string s,t; cin >> s >> t;
    char tmp = ' ';
    int size1 = s.size(),size2 = t.size(),si = 0,ti = 0;
    while(true){
        int cs = 0,ct = 0;
        tmp = s[si];
        if(tmp != t[ti])return cout << "No" << endl,0;
        while(si != size1 && tmp == s[si]){
            si++;
            cs++;
        }
        while(ti != size2 && tmp == t[ti]){
            ti++;
            ct++;
        }
        if( (cs <= 1 && ct >= 2) || (cs >= 2 && ct <= 1) )return cout << "No" << endl,0;
        if(si == size1 || ti == size2)break;
    }
    if(si == size1 && ti == size2)cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}
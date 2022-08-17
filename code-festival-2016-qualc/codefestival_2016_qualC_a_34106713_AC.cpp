/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/code-festival-2016-qualc/submissions/34106713
 * Submitted at: 2022-08-17 18:13:09
 * Problem URL: https://atcoder.jp/contests/code-festival-2016-qualc/tasks/codefestival_2016_qualC_a
 * Result: AC
 * Execution Time: 7 ms
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
    
    string s; cin >> s;
    bool f = false;
    rep(i,s.size()){
        if(f && s[i] == 'F')return cout << "Yes" << endl,0;
        if(s[i] == 'C')f = true;
    }
    cout << "No" << endl;
    
    return 0;
}
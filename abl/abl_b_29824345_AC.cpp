/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abl/submissions/29824345
 * Submitted at: 2022-03-03 18:44:12
 * Problem URL: https://atcoder.jp/contests/abl/tasks/abl_b
 * Result: AC
 * Execution Time: 13 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    ll a,b,c,d; cin >> a >> b >> c >> d;
    if(b <= d){
        if(c <= b)cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    else{
        if(a <= d)cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}
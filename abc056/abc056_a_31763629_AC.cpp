/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc056/submissions/31763629
 * Submitted at: 2022-05-17 19:13:59
 * Problem URL: https://atcoder.jp/contests/abc056/tasks/abc056_a
 * Result: AC
 * Execution Time: 5 ms
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
    
    char a,b; cin >> a >> b;
    if(a == 'H'){
        if(b == 'H')cout << 'H' << endl;
        else cout << 'D' << endl;
    }
    else{
        if(b == 'H')cout << 'D' << endl;
        else cout << 'H' << endl;
    }
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/code-formula-2014-final/submissions/33392786
 * Submitted at: 2022-07-21 18:21:56
 * Problem URL: https://atcoder.jp/contests/code-formula-2014-final/tasks/code_formula_2014_final_a
 * Result: AC
 * Execution Time: 17 ms
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
    
    ll a,b; cin >> a >> b;
    cout << a*b << endl;
    
    return 0;
}
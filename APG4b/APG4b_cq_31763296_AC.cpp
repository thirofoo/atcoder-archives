/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/APG4b/submissions/31763296
 * Submitted at: 2022-05-17 18:52:51
 * Problem URL: https://atcoder.jp/contests/APG4b/tasks/APG4b_cq
 * Result: AC
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
    
    int a,b; char op; cin >> a >> op >> b;
    if(op == '+')cout << a+b << endl;
    else if(op == '-')cout << a-b << endl;
    else if(op == '*')cout << a*b << endl;
    else if(op == '/'){
        if(b == 0)cout << "error" << endl;
        else cout << a/b << endl;
    }
    else cout << "error" << endl;
    
    return 0;
}
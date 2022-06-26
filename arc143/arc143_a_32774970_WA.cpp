/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc143/submissions/32774970
 * Submitted at: 2022-06-26 21:27:03
 * Problem URL: https://atcoder.jp/contests/arc143/tasks/arc143_a
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
    
    ll a,b,c; cin >> a >> b >> c;
    priority_queue<ll> sor;
    sor.push(a);
    sor.push(b);
    sor.push(c);
    a = sor.top(); sor.pop();
    b = sor.top(); sor.pop();
    c = sor.top(); sor.pop();
    if(a > b+c)return cout << -1 << endl,0;
    else if(c == b && (a-c)%2 == 0)cout << (a-c)/2 + c << endl;
    else if((a-c+b-c)%2 == 0)cout << (a-c+b-c)/2 + c << endl;
    else cout << a << endl;

    return 0;
}
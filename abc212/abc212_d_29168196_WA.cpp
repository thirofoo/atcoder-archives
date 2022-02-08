/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc212/submissions/29168196
 * Submitted at: 2022-02-08 23:17:35
 * Problem URL: https://atcoder.jp/contests/abc212/tasks/abc212_d
 * Result: WA
 * Execution Time: 206 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
 
int main() {
    int q; cin >> q;
    ll cnt = 0,add;
    priority_queue<P,vector<P>,greater<P>> ball;
    vector<ll> inc; inc.push_back(0);
    rep(i,q){
        int p; cin >> p;
        if(p == 1){
            ll x; cin >> x;
            ball.push(P(x,INT_MAX-cnt));
        }
        else if(p == 2){
            ll x; cin >> x;
            inc.push_back(x+*(inc.end()-1));
            cnt++;
        }
        else{
            auto [x,y] = ball.top(); ball.pop();
            y = INT_MAX - y;
            add = inc[cnt]-inc[y];
            cout << x + add << endl;
        }
    }
    return 0;
}
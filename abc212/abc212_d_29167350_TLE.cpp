/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc212/submissions/29167350
 * Submitted at: 2022-02-08 22:43:33
 * Problem URL: https://atcoder.jp/contests/abc212/tasks/abc212_d
 * Result: TLE
 * Execution Time: 2205 ms
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
    int q; cin >> q;
    priority_queue<ll,vector<ll>,greater<ll>> ball;
    queue<ll> hold;
    rep(i,q){
        int p; cin >> p;
        if(p == 1){
            ll x; cin >> x;
            ball.push(x);
        }
        else if(p == 2){
            ll x; cin >> x;
            while(!ball.empty()){
                ll tmp = ball.top(); ball.pop();
                hold.push(tmp+x);
            }
            while(!hold.empty()){
                ll tmp = hold.front(); hold.pop();
                ball.push(tmp);
            }
        }
        else{
            ll tmp = ball.top(); ball.pop();
            cout << tmp << endl;
        }
    }
    return 0;
}
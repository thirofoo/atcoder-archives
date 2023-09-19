/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc155/submissions/45717434
 * Submitted at: 2023-09-19 09:17:20
 * Problem URL: https://atcoder.jp/contests/abc155/tasks/abc155_c
 * Result: AC
 * Execution Time: 454 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, string>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    map<string,ll> mp;
    rep(i,n) {
        string s; cin >> s;
        mp[s]++;
    }
    priority_queue<P> todo;
    for(auto [key,value]:mp) {
        todo.push(P(value,key));
    }
    ll time = 0;
    stack<string> ans;
    while( !todo.empty() ) {
        auto [num, s] = todo.top(); todo.pop();
        if( num < time ) break;
        time = num;
        ans.push(s);
    }
    while( !ans.empty() ) {
        cout << ans.top() << endl;
        ans.pop();
    }

    return 0;
}
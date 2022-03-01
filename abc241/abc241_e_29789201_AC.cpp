/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc241/submissions/29789201
 * Submitted at: 2022-03-01 18:41:30
 * Problem URL: https://atcoder.jp/contests/abc241/tasks/abc241_e
 * Result: AC
 * Execution Time: 157 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    ll n,k,x = 0,total_turn = 0; cin >> n >> k;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    vector<ll> turn(n+1,0);
    map<ll,P> ans;

    while(!ans[x%n].first){
        total_turn++;
        ans[x%n] = P(x+a[x%n],total_turn);
        x += a[x%n];
        turn[total_turn] = x;
    }

    ll T = total_turn-ans[x%n].second+1;
    ll T_cost = x-ans[x%n].first+a[x%n];

    ll preT_cost = 0,preT_turn = 0;
    while(preT_cost%n != x%n){
        preT_turn++;
        preT_cost += a[preT_cost%n];
        if(k <= preT_turn)return cout << preT_cost << endl,0;
    }
    // cout << preT_cost << " " << T << " " << k-preT_turn << " " << T_cost << endl;
    cout << preT_cost   +   ((k-preT_turn)/T)*T_cost   +   turn[(k-preT_turn)%T+preT_turn]-preT_cost << endl;
    
    return 0;
}
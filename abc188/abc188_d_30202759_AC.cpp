/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc188/submissions/30202759
 * Submitted at: 2022-03-18 18:10:30
 * Problem URL: https://atcoder.jp/contests/abc188/tasks/abc188_d
 * Result: AC
 * Execution Time: 222 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    ll n,C; cin >> n >> C;
    ll ans = 0,tmp = 0,now_date = 1;
    priority_queue<P,vector<P>,greater<P>> service;
    vector<int> price(n);
    rep(i,n){
        int a,b,c; cin >> a >> b >> c;
        service.push(P(a,i));
        service.push(P(b+1,i));
        price[i] = c;
    }

    vector<bool> frag(n,false);
    while(!service.empty()){
        auto [date,i] = service.top(); service.pop();
        ans += min(tmp,C)*(date-now_date);
        now_date = date;
        if(frag[i]){
            frag[i] = false;
            tmp -= price[i];
        }
        else{
            frag[i] = true;
            tmp += price[i];
        }
    }
    
    cout << ans << endl;
    return 0;
}
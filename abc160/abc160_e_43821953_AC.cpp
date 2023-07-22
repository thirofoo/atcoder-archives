/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc160/submissions/43821953
 * Submitted at: 2023-07-22 17:32:52
 * Problem URL: https://atcoder.jp/contests/abc160/tasks/abc160_e
 * Result: AC
 * Execution Time: 63 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll x,y,a,b,c; cin >> x >> y >> a >> b >> c;
    vector<P> apple;
    rep(i,a){
        ll p; cin >> p;
        apple.push_back(P(p,0));
    }
    rep(i,b){
        ll p; cin >> p;
        apple.push_back(P(p,1));
    }
    rep(i,c){
        ll p; cin >> p;
        apple.push_back(P(p,2));
    }
    sort( apple.begin(), apple.end(), [](P e1, P e2){
        return e1.first > e2.first;
    } );
    ll red = 0, green = 0, trance = 0, now = 0, ans = 0;
    while( red + green + trance < x + y ){
        auto [cost, color] = apple[now];
        now++;
        if( color == 0 && red == x ) continue;
        if( color == 1 && green == y ) continue;
        switch( color ){
            case 0: 
                red++;
                break;
            case 1: 
                green++;
                break;
            case 2: trance++;
        }
        ans += cost;
    }
    cout << ans << endl;
    
    return 0;
}
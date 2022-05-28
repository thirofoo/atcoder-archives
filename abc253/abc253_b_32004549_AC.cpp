/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc253/submissions/32004549
 * Submitted at: 2022-05-28 21:04:57
 * Problem URL: https://atcoder.jp/contests/abc253/tasks/abc253_b
 * Result: AC
 * Execution Time: 10 ms
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
    
    int h,w; cin >> h >> w;
    queue<P> p;
    vector<string> s(h);
    rep(i,h)cin >> s[i];
    rep(i,h){
        rep(j,w){
            if(s[i][j] == 'o')p.push(P(i,j));
        }
    }
    auto [x1,y1] = p.front(); p.pop();
    auto [x2,y2] = p.front(); p.pop();
    cout << abs(x1-x2)+abs(y1-y2) << endl;
    return 0;
}
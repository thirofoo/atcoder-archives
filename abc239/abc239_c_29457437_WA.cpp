/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc239/submissions/29457437
 * Submitted at: 2022-02-19 21:47:11
 * Problem URL: https://atcoder.jp/contests/abc239/tasks/abc239_c
 * Result: WA
 * Execution Time: 6 ms
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

vector<ll> mx = {-2,-2,-1,-1,1,1,2,2};
vector<ll> my = {1,-1,2,-2,2,-2,1,-1};

int main() {
    ll x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
    if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) > 20 || y1 == y2)return cout << "No" << endl,0;
    rep(i,mx.size()){
        ll x = x1+mx[i],y = y1+my[i];
        if(x1*x1+y1*y1-x2*x2-y2*y2 == 2*(x1-x2)*x + 2*(y1-y2)*y)return cout << "Yes" << endl,0;
    }
    cout << "No" << endl;
    return 0;
}
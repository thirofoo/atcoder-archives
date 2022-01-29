/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc223/submissions/28849776
 * Submitted at: 2022-01-29 11:53:46
 * Problem URL: https://atcoder.jp/contests/abc223/tasks/abc223_c
 * Result: AC
 * Execution Time: 48 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<double, double> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cout << setprecision(8);
    int n,i = 0; cin >> n;
    double time = 0,total = 0,ans = 0;
    vector<P> fire;
    rep(i,n){
        int a,b; cin >> a >> b;
        fire.push_back(P(a,b));
        total += (double)a/b; 
    }
    total /= 2;
    while(total > fire[i].first/fire[i].second){
        total -= fire[i].first/fire[i].second; 
        ans += fire[i].first; i++;
    }
    ans += total*fire[i].second;
    cout << ans << endl;
    return 0;
}
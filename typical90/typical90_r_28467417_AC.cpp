/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28467417
 * Submitted at: 2022-01-11 22:26:58
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_r
 * Result: AC
 * Execution Time: 13 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cout << fixed << setprecision(10);
    int T,l,x,y,q; cin >> T >> l >> x >> y >> q;
    vector<int> time(q);
    rep(i,q){
        int tmp; cin >> tmp;
        tmp %= T;
        time[i] = tmp; 
    }
    rep(i,q){
        double bunbo = 2*sqrt(pow(x,2)+pow(y+l*sin(2*M_PI*time[i]/T)/2,2));
        double bunshi = l*(1-cos(2*M_PI*time[i]/T));
        double tangent = bunshi/bunbo;
        double left = 0,right = M_PI/2;
        while(right-left > 0.0000000001){
            double mid = (right+left)/2;
            if(tangent >= tan(mid))left = mid;
            else right = mid;
        }
        cout << (360*left)/(2*M_PI) << endl;
    }
    return 0;
}
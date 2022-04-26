/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc139/submissions/31281746
 * Submitted at: 2022-04-26 16:46:55
 * Problem URL: https://atcoder.jp/contests/arc139/tasks/arc139_b
 * Result: WA
 * Execution Time: 12 ms
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
    int t,n,a,b,x,y,z;
    cin >> t;

    rep(i,t){
        int ans = INT_MAX;
        cin >> n >> a >> b >> x >> y >> z;

        //+1あたりのコストが少ない方をyとする。
        if((double)y/a > (double)z/b){
            swap(y,z); swap(a,b);
        }

        //c1 : +aするのにコストが少ない方
        //c2 : +bするのにコストが少ない方
        int c1 = min(y,a*x),c2 = min(z,b*x);
        if(n/a <= a-1){
            for(int j=0;j<=n/a;j++){
                int rest = n-a*j,cost = c1*j;
                cost += (rest/b)*c2;
                rest -= (rest/b)*b;
                cost += x*rest;
                ans = min(ans,cost);
            }
        }
        else{
            for(int j=0;j<=a-1;j++){
                int rest = n-b*j,cost = c2*j;
                cost += (rest/a)*c1;
                rest -= (rest/a)*a;
                cost += x*rest;
                ans = min(ans,cost);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
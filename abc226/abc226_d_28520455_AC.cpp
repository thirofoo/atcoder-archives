/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc226/submissions/28520455
 * Submitted at: 2022-01-15 16:33:02
 * Problem URL: https://atcoder.jp/contests/abc226/tasks/abc226_d
 * Result: AC
 * Execution Time: 49 ms
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
    int n,x = 0,y = 0; cin >> n;
    set<double> tilt;
    vector<P> vertex;
    rep(i,n){
        int a,b; cin >> a >> b;
        vertex.push_back(P(a,b));
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            double a,b,c,d;
            tie(a,b) = vertex[i];
            tie(c,d) = vertex[j];
            if(a == c)x = 1;
            else if(b == d)y = 1;
            else tilt.insert((d-b)/(a-c));
        }
    }
    cout << (tilt.size()+x+y)*2 << endl;
    return 0;
}
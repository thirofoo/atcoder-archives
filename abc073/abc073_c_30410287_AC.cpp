/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc073/submissions/30410287
 * Submitted at: 2022-03-26 11:48:21
 * Problem URL: https://atcoder.jp/contests/abc073/tasks/abc073_c
 * Result: AC
 * Execution Time: 71 ms
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
    int n; cin >> n; 
    map<int,int> x;
    set<int> a;
    rep(i,n){
        int tmp; cin >> tmp;
        x[tmp]++;
    }
    
    int ans = 0;
    for(auto [c,d]:x)if(d%2)ans++;
    cout << ans << endl;
    return 0;
}
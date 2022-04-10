/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc247/submissions/30862447
 * Submitted at: 2022-04-10 21:19:54
 * Problem URL: https://atcoder.jp/contests/abc247/tasks/abc247_c
 * Result: AC
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
    int n; cin >> n;
    vector<vector<int>> ans(n);
    
    rep(i,n){
        if(i == 0){
            ans[i].push_back(1);
        }
        else{
            for(auto k:ans[i-1])ans[i].push_back(k);
            ans[i].push_back(i+1);
            for(auto k:ans[i-1])ans[i].push_back(k);
        }
    }
    
    for(auto k:ans[n-1])cout << k << " ";
    cout << endl;
    
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28461768
 * Submitted at: 2022-01-11 15:49:58
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_g
 * Result: AC
 * Execution Time: 643 ms
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
    int n; cin >> n;
    vector<int> classes(n);
    rep(i,n)cin >> classes[i];
    sort(classes.begin(),classes.end());
    int left = -1,right = n,q; cin >> q;
    vector<int> ans;
    rep(i,q){
        int rate; cin >> rate;
        while(right-left > 1){
            int mid = (right+left)/2;
            if(rate >= classes[mid])left = mid;
            else right = mid;
        }
        if(left == -1) ans.push_back(abs(classes[0]-rate));
        else if(left == n-1) ans.push_back(abs(classes[n-1]-rate));
        else ans.push_back(min(abs(classes[left]-rate),abs(classes[left+1]-rate)));
        left = -1; right = n;
    }
    rep(i,q)cout << ans[i] << endl;
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc211/submissions/29174666
 * Submitted at: 2022-02-09 11:46:23
 * Problem URL: https://atcoder.jp/contests/abc211/tasks/abc211_b
 * Result: AC
 * Execution Time: 3 ms
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

int main() {
    map<string,int> ans;
    rep(i,4){
        string tmp; cin >> tmp;
        ans[tmp]++;
    }
    if(ans["H"] && ans["2B"] && ans["3B"] && ans["HR"])cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
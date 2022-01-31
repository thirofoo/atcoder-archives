/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc217/submissions/28973958
 * Submitted at: 2022-01-31 18:57:19
 * Problem URL: https://atcoder.jp/contests/abc217/tasks/abc217_b
 * Result: AC
 * Execution Time: 8 ms
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
    vector<string> str = {"ABC","ARC","AGC","AHC"};
    vector<int> ans(4,0);
    rep(i,3){
        string tmp; cin >> tmp;
        rep(j,4){
            if(tmp == str[j])ans[j]++;
        }
    }
    rep(i,4)if(!ans[i])cout << str[i] << endl;;
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc237/submissions/28911019
 * Submitted at: 2022-01-30 21:12:10
 * Problem URL: https://atcoder.jp/contests/abc237/tasks/abc237_d
 * Result: TLE
 * Execution Time: 2205 ms
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
    vector<int> ans; ans.push_back(0);
    int n,tmp = 0; string s; cin >> n >> s;
    rep(i,s.size()){
        if(s[i] == 'L'){
            ans.insert(ans.begin()+tmp,i+1);
        }
        else{
            tmp++;
            ans.insert(ans.begin()+tmp,i+1);
        }
    }
    rep(i,ans.size())cout << ans[i] << " ";
    cout << endl;
    return 0;
}
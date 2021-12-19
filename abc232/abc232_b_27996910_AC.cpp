/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc232/submissions/27996910
 * Submitted at: 2021-12-19 21:19:31
 * Problem URL: https://atcoder.jp/contests/abc232/tasks/abc232_b
 * Result: AC
 * Execution Time: 20 ms
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
    string s,t;
    cin >> s >> t;
    rep(i,30){
        string ans = s;
        for(int j=0;j<ans.size();j++){
            if(ans[j] + i > 'z')ans[j] = 'a' + i-('z'-ans[j]) - 1;
            else ans[j] += i;
        }
        if(ans == t)return cout << "Yes" << endl,0;
    }
    cout << "No" << endl;
    return 0;
}
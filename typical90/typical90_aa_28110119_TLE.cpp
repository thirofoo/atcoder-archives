/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28110119
 * Submitted at: 2021-12-25 20:55:39
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_aa
 * Result: TLE
 * Execution Time: 1103 ms
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
    int n;
    cin >> n;
    vector<string> name;
    rep(i,n){
        string user;
        cin >> user;
        if(count(name.begin(),name.end(),user))continue;
        name.push_back(user);
        cout << i+1 << endl;
    }
    return 0;
}
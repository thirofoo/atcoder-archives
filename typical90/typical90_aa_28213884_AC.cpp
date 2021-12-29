/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28213884
 * Submitted at: 2021-12-29 11:02:02
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_aa
 * Result: AC
 * Execution Time: 245 ms
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
    map<string,int> name;
    rep(i,n){
        string user; cin >> user;
		if(!name.count(user))cout << i+1 << endl;
		name[user]++;
    }
    return 0;
}
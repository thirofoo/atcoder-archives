/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc236/submissions/28734717
 * Submitted at: 2022-01-23 21:13:02
 * Problem URL: https://atcoder.jp/contests/abc236/tasks/abc236_c
 * Result: AC
 * Execution Time: 294 ms
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
    int n,m; cin >> n >> m;
    vector<string> station(n);
    map<string,int> exp;
    rep(i,n)cin >> station[i];
    rep(i,m){
        string s; cin >> s;
        exp[s]++;
    }
    rep(i,n){
        if(exp[station[i]])cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc187/submissions/31338933
 * Submitted at: 2022-04-29 16:12:18
 * Problem URL: https://atcoder.jp/contests/abc187/tasks/abc187_c
 * Result: AC
 * Execution Time: 415 ms
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
    vector<string> a;
    map<string,int> str;
    rep(i,n){
        string s; cin >> s;
        a.push_back(s);
        str[s]++;
    }
    rep(i,n){
        if(str[a[i]] && str["!"+a[i]]){
            return cout << a[i] << endl,0;
        }
    }
    cout << "satisfiable" << endl;
    return 0;
}
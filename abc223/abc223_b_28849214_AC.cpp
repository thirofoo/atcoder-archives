/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc223/submissions/28849214
 * Submitted at: 2022-01-29 11:03:47
 * Problem URL: https://atcoder.jp/contests/abc223/tasks/abc223_b
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
    string s; cin >> s;
    vector<string> str;
    str.push_back(s);
    rep(i,s.size()-1){
        string tmp = "";
        tmp += s[0];
        s.erase(0,1);
        s += tmp;
        str.push_back(s);
    }
    sort(str.begin(),str.end());
    cout << str[0] << endl << str[str.size()-1] << endl;
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc221/submissions/28973711
 * Submitted at: 2022-01-31 18:43:44
 * Problem URL: https://atcoder.jp/contests/abc221/tasks/abc221_b
 * Result: WA
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
    string s,t; cin >> s >> t;
    int count = 0;
    vector<char> a,b;
    rep(i,s.size()){
        a.push_back(s[i]); b.push_back(t[i]);
        if(s[i] == t[i+1] && s[i+1] == t[i])count++;
        if(count == 2)return cout << "No" << endl,0;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(a == b)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
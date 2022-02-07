/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc219/submissions/29139092
 * Submitted at: 2022-02-07 12:32:12
 * Problem URL: https://atcoder.jp/contests/abc219/tasks/abc219_c
 * Result: AC
 * Execution Time: 119 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<string,string> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    string x; cin >> x;
    string abc = "abcdefghijklmnopqrstuvwxyz";
    vector<P> ans;
    int n; cin >> n;
    rep(i,n){
        string str,tmp = ""; cin >> str;
        rep(i,str.size()){
            tmp += abc[find(x.begin(),x.end(),str[i])-x.begin()];
        }
        ans.push_back(P(tmp,str));
    }
    sort(ans.begin(),ans.end());
    rep(i,ans.size())cout << ans[i].second << endl;
    return 0;
}
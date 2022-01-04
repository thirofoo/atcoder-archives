/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc230/submissions/28320368
 * Submitted at: 2022-01-04 15:55:10
 * Problem URL: https://atcoder.jp/contests/abc230/tasks/abc230_b
 * Result: AC
 * Execution Time: 6 ms
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
    int i=0;
    string s,ans = ""; cin >> s;
    vector<string> p = {"oxx","xxo","xox"};
    if(s == "oo")return cout << "No" << endl,0;
    else if(s.size() <= 2)return cout << "Yes" << endl,0;
    for(auto a:p){
        if(s.substr(0,3) != a)continue;
        while(ans.size() != s.size()){
            if(i+2 <= s.size()-1)ans += a;
            else if(i+1 > s.size()-1)ans += a.substr(0,1);
            else ans += a.substr(0,2);
            i += 3;
        }
    }
    if(s == ans)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
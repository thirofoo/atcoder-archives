/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc231/submissions/28983712
 * Submitted at: 2022-02-01 10:42:15
 * Problem URL: https://atcoder.jp/contests/abc231/tasks/abc231_b
 * Result: AC
 * Execution Time: 7 ms
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
    int n,ans = 0; cin >> n;
    map<string,int> ele;
    string cand = "";
    rep(i,n){
        string tmp; cin >> tmp;
        ele[tmp]++;
        if(ans < ele[tmp]){
            cand = tmp;
            ans = ele[tmp];
        }
    }
    cout << cand << endl;
    return 0;
}
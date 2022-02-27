/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc136/submissions/29743391
 * Submitted at: 2022-02-27 21:16:10
 * Problem URL: https://atcoder.jp/contests/arc136/tasks/arc136_a
 * Result: AC
 * Execution Time: 14 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n; string s; cin >> n >> s;
    string ans = "";
    rep(i,n){
        if(s[i] == 'C' || s[i] == 'A' || i == n-1){
            ans += s[i];
            continue;
        }
        if(s[i+1] == 'A'){
            ans += s[i+1];
            swap(s[i],s[i+1]);
        }
        else if(s[i+1] == 'B'){
            ans += 'A';
            i++;
        }
        else ans += s[i];
    }
    cout << ans << endl;
    return 0;
}
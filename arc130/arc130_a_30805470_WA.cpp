/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc130/submissions/30805470
 * Submitted at: 2022-04-09 18:15:04
 * Problem URL: https://atcoder.jp/contests/arc130/tasks/arc130_a
 * Result: WA
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
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,cnt = 1,ans = 0; string s; cin >> n >> s;
    rep(i,s.size()-1){
        if(s[i+1] == s[i])cnt++;
        else{
            ans += cnt*(cnt-1)/2;
            cnt = 1;
        }
    }
    ans += cnt*(cnt-1)/2;
    cout << ans << endl;
    return 0;
}
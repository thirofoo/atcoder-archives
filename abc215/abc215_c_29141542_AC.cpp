/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc215/submissions/29141542
 * Submitted at: 2022-02-07 15:32:57
 * Problem URL: https://atcoder.jp/contests/abc215/tasks/abc215_c
 * Result: AC
 * Execution Time: 13 ms
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
    int k; cin >> k;
    vector<string> ans;
    sort(s.begin(),s.end());
    do{
        ans.push_back(s);
    }while(next_permutation(s.begin(),s.end()));
    sort(ans.begin(),ans.end());
    cout << ans[k-1] << endl;
    return 0;
}
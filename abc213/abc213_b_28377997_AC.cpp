/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc213/submissions/28377997
 * Submitted at: 2022-01-08 20:11:35
 * Problem URL: https://atcoder.jp/contests/abc213/tasks/abc213_b
 * Result: AC
 * Execution Time: 78 ms
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
    int n; cin >> n;
    vector<int> score(n),ans(n);
    rep(i,n)cin >> score[i];
    ans = score;
    sort(score.begin(),score.end(),[](int a,int b){
        return a > b;
    });
    int answer = find(ans.begin(),ans.end(),score[1])-ans.begin()+1;
    cout << answer << endl;
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc221/submissions/29000526
 * Submitted at: 2022-02-02 11:29:16
 * Problem URL: https://atcoder.jp/contests/abc221/tasks/abc221_c
 * Result: AC
 * Execution Time: 44 ms
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
    string n; cin >> n;
    sort(n.begin(),n.end());
    int half = n.size()/2,size = n.size(),ans = 0;
    do{
        string tmp1 = "",tmp2 = "";
        rep(i,half)tmp1 += n[i];
        for(int j=half;j<size;j++)tmp2 += n[j];
        int cand = stoi(tmp1)*stoi(tmp2);
        ans = max(ans,cand);
    }while(next_permutation(n.begin(),n.end()));
    cout << ans << endl;
    return 0;
}
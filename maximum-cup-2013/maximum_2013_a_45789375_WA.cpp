/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/maximum-cup-2013/submissions/45789375
 * Submitted at: 2023-09-22 16:15:48
 * Problem URL: https://atcoder.jp/contests/maximum-cup-2013/tasks/maximum_2013_a
 * Result: WA
 * Execution Time: 1 ms
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<vector<int>> e;
    int ans = 0, tmp = 0;
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            cin >> tmp;
            ans += ( (i == 0 || (i == 0 && j == n-2)) ? tmp : 0 );
        }
    }
    cout << n << " " << ans << endl;
    
    
    return 0;
}
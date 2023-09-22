/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc164/submissions/45784088
 * Submitted at: 2023-09-22 10:18:13
 * Problem URL: https://atcoder.jp/contests/abc164/tasks/abc164_c
 * Result: AC
 * Execution Time: 49 ms
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    unordered_map<string,int> mp;
    string s;
    for(int i=0;i<n;i++) {
        cin >> s;
        mp[s]++;
    }
    cout << mp.size() << endl;
    
    return 0;
}
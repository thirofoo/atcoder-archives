/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc301/submissions/41393873
 * Submitted at: 2023-05-13 23:05:23
 * Problem URL: https://atcoder.jp/contests/abc301/tasks/abc301_b
 * Result: AC
 * Execution Time: 6 ms
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin >> a[i];

    cout << a[0] << " ";
    for(int i=0;i<n-1;i++){
        if(a[i] < a[i+1]){
            for(int j = a[i]+1; j <= a[i+1]; j++){
                cout << j << " ";
            }
        }
        if(a[i] > a[i+1]){
            for(int j=a[i]-1; j>=a[i+1]; j--){
                cout << j << " ";
            }
        }
    }
    cout << endl;
    
    return 0;
}
/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc182/submissions/44448255
 * Submitted at: 2023-08-11 11:22:22
 * Problem URL: https://atcoder.jp/contests/abc182/tasks/abc182_b
 * Result: AC
 * Execution Time: 8 ms
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,b=0,ans=0;
    cin >> n;
    vector<int> a(n);
    
    for(int i=0;i<n;i++){
        cin >> a.at(i);
    }
    
    sort(a.begin(), a.end(), greater<int>());
    cout << endl;

    vector<int> c((a.at(0))+1,0);
    for(int i=2;i<=a.at(0);i++){
        for(int j=0;j<n;j++){
            if(a.at(j)%i==0){
                c.at(i)++;
            }        
        }
    }
    
    for(int i=2;i<=a.at(0);i++){
        if(c.at(i)>=b){
            b=c.at(i);
            ans=i;
        }
    }

    cout << ans <<endl;
}
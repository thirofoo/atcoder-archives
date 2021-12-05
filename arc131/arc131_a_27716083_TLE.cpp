/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc131/submissions/27716083
 * Submitted at: 2021-12-05 21:20:59
 * Problem URL: https://atcoder.jp/contests/arc131/tasks/arc131_a
 * Result: TLE
 * Execution Time: 2205 ms
 */

#include <bits/stdc++.h>
#include <cmath> //abs関数で絶対値を使える。
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < n; ++i)

int main(){
    string a,b,lucky;
    cin >> a >> b;
    for(int i=stoi(b);i<1e18;i++){
        ll i2 = i*2;
        string i_ = to_string(i);
        string i2_ = to_string(i2);
        if(i_.find(a) != i_.npos){
            if(i2_.find(b) != i2_.npos){
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
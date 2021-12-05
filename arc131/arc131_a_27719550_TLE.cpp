/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc131/submissions/27719550
 * Submitted at: 2021-12-05 21:52:37
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
    string a,b;
    cin >> a >> b;
    for(int i=0;i<1e18;i++){
        ll i1 = stoi(a) + i*10*(a.size()+1);
        ll i11 = stoi(a)*10*to_string(i).size() + i;
        ll i2 = i1*2;
        ll i22 = i11*2;
        string i1_ = to_string(i1);
        string i11_ = to_string(i11);
        string i2_ = to_string(i2);
        string i22_ = to_string(i22);
        if(i1_.find(a) != i1_.npos){
            if(i2_.find(b) != i2_.npos){
                cout << i1 << endl;
                break;
            }
        }
        if(i11_.find(a) != i11_.npos){
            if(i22_.find(b) != i22_.npos){
                cout << i11 << endl;
                break;
            }
        }
    }
    return 0;
}
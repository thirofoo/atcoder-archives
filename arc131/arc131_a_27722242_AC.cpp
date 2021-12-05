/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc131/submissions/27722242
 * Submitted at: 2021-12-05 22:25:44
 * Problem URL: https://atcoder.jp/contests/arc131/tasks/arc131_a
 * Result: AC
 * Execution Time: 7 ms
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
    ll a,b;
    cin >> a >> b;
    if(b%2 == 0){
        string b_ = to_string(b/2);
        string a_ = to_string(a);
        cout << a_+"0"+b_ << endl;
    }
    else{
        string b_ = to_string(b/2);
        string a_ = to_string(a);
        cout << a_+"0"+b_+"5" << endl;
    } 
    return 0;
}
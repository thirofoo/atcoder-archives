/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc216/submissions/29139288
 * Submitted at: 2022-02-07 12:47:20
 * Problem URL: https://atcoder.jp/contests/abc216/tasks/abc216_c
 * Result: WA
 * Execution Time: 6 ms
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
    ll n,count = 0; cin >> n;
    while(n != 1){
        if(n%2 == 0){
            n /= 2;
            cout << "B";
        }
        else{
            n -= 1;
            cout << "A";
        }
    }
    cout << endl;
    return 0;
}
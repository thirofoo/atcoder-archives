/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc190/submissions/30610751
 * Submitted at: 2022-04-01 23:43:09
 * Problem URL: https://atcoder.jp/contests/abc190/tasks/abc190_a
 * Result: AC
 * Execution Time: 8 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int a,b,c; cin >> a >> b >> c;
    if(c == 0){
        if(a <= b)cout << "Aoki" << endl;
        else cout << "Takahashi" << endl;
    }
    else{
        if(b <= a)cout << "Takahashi" << endl;
        else cout << "Aoki" << endl;
    }
    return 0;
}
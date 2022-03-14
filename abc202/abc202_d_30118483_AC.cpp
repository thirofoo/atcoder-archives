/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc202/submissions/30118483
 * Submitted at: 2022-03-14 11:49:10
 * Problem URL: https://atcoder.jp/contests/abc202/tasks/abc202_d
 * Result: AC
 * Execution Time: 7 ms
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
    ll a,b,k;
    cin >> a >> b >> k;
    int s = a + b;
    string ans = "";
    rep(i,s){
        //sa:aを選んだ時の残りの文字列の総数
        ll sa = 1;
        for(int j=1;j<a;j++){
            //(a+b-1)C(a-1)
            sa *= a + b - j;
            sa /= j;
        }
        if(a == 0)sa = 0;

        //辞書順的にa側かb側か
        if(k <= sa){
            ans += "a";
            a--;
        }
        else {
            ans += "b";
            k -= sa;
            b--;
        }
    }
    cout << ans << endl;
    return 0;
}
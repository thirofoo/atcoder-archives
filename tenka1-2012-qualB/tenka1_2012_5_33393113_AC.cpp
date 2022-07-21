/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/tenka1-2012-qualB/submissions/33393113
 * Submitted at: 2022-07-21 18:45:22
 * Problem URL: https://atcoder.jp/contests/tenka1-2012-qualB/tasks/tenka1_2012_5
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
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int a,b,c; cin >> a >> b >> c;
    for(int i=1;i<=127;i++){
        if(((i-a)%3+3)%3 == 0 && ((i-b)%5+5)%5 == 0 && ((i-c)%7+7)%7 == 0){
            cout << i << endl;
        }
    }
    
    return 0;
}
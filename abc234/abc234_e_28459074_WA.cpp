/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc234/submissions/28459074
 * Submitted at: 2022-01-11 10:59:05
 * Problem URL: https://atcoder.jp/contests/abc234/tasks/abc234_e
 * Result: WA
 * Execution Time: 8 ms
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
    ll ans = pow(10,17),a = -9;
    string x; cin >> x;
    for(int j=0;j<2;j++){
        while(true){
            bool frag = true;
            string cand = "";
            if(x[0]+j > '9')break;
            cand.push_back(x[0]+j);
            rep(i,x.size()-1){
                cand.push_back(cand[i] + a + j);
                if(cand[i+1] > '9' || cand[i+1] < '0')frag = false;
            }
            if(frag && cand >= x)ans = min(ans,stoll(cand));
            a++;
            if(a == 9)break;
        }
        a = -9;
    }
    cout << ans << endl;
    return 0;
}
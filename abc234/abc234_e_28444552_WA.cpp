/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc234/submissions/28444552
 * Submitted at: 2022-01-10 11:51:17
 * Problem URL: https://atcoder.jp/contests/abc234/tasks/abc234_e
 * Result: WA
 * Execution Time: 7 ms
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
    ll ans = 11111111111,a = -9;
    string x; cin >> x;
    if(x.size() <= 2)cout << x << endl;
    else if(x.size() > 10){
        if(x[0] >= x[1])rep(i,x.size())cout << x[0];
        else rep(i,x.size())cout << x[0]+1;
        cout << endl;
    }
    else{
        while(true){
            bool frag1 = true,frag2 = true;
            string cand1 = "",cand2 = "";
            cand1.push_back(x[0]);
            cand2.push_back(x[0]+1);
            rep(i,x.size()-1){
                cand1.push_back(cand1[i] + a);
                cand2.push_back(cand2[i] + a);
                if(cand1[i+1] > '9' || cand1[i+1] < '0'){frag1 = false;}
                if(cand2[i+1] > '9' || cand2[i+1] < '0'){frag2 = false;}
            }
            if(frag1 && cand1 >= x)ans = min(ans,stoll(cand1));
            if(x[0] != '9' && frag2 && cand2 >= x)ans = min(ans,stoll(cand2));
            a++;
            if(a == 9)break;
        }
        cout << ans << endl;
    }
    return 0;
}